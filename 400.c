#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char id[240]; // 군사 부대 번호
	
} MilitarySite;

typedef struct {
	char id[240]; // 군번
	char name[300]; // 성명
	MilitarySite RelationShip; // 소속
	char rank[120]; // 계급
} Soilder;


Soilder* manager = NULL; // 담당관
Soilder* currentUser = NULL; // 현재 유저
Soilder** user = NULL; // 사용자 목록


int soilderCount = 0; // 군인 수

void removeNewLine(char* str)
{
	str[strcspn(str, "\n")] = '\0';
}


typedef struct {
	int id; // 책 번호
	char title[1000]; // 책 이름
	char author[300]; // 저자
	int isBorrowed; // 대출 가능 여부, 0은 가능, 1은 불가
	Soilder registor, borrowor; // registor은 책을 등록한 사람, borrowor은 책을 대여한 사람
} Book;

Book* library = NULL;

int bookCount = 0; // 책의 개수
int maxBooks = 100; // 도서관에 수용 가능한 최대 도서 수



/**
	책을 추가하기 위한 함수입니다.
*/
void addBook() {

	if (bookCount >= maxBooks)
	{
		printf("도서관이 가득 찼습니다. 더 이상 도서를 추가할 수 없습니다. \n");
		return;
	}

	Book newBook;
	newBook.id = bookCount + 1; // 도서번호 할당

	printf("도서 제목 : ");

	getchar();

	fgets(newBook.title, sizeof(newBook.title), stdin);
	removeNewLine(newBook.title);

	printf("저자 이름: ");
	fgets(newBook.author, sizeof(newBook.author), stdin);
	removeNewLine(newBook.author);

	newBook.isBorrowed = 0;
	newBook.registor = *currentUser;
	newBook.borrowor = *currentUser; // 초기 설정값			


	library[bookCount++] = newBook;


	printf("\n======도서가 추가되었습니다. 도서 번호: %d======\n", newBook.id);
}

/**

책을 표시하기 위한 함수입니다.

*/
void displayBooks() {

	if (bookCount == 0)
	{
		printf("\n현재 보유 중인 도서가 없습니다.\n");
		return;
	}

	printf("\n===== 보유 중인 도서 목록 =====\n");
	for (int i = 0; i < bookCount; i++) {
		printf("도서 번호 : %d\t 제목: %s\t 저자: %s\t 대출 여부: %s\t 대출자 이름: %s \n",
			library[i].id, library[i].title, library[i].author,
			library[i].isBorrowed ? "대출 중" : "대출 가능", library[i].borrowor.name);
	}
	printf("\n=============================\n");

}

/** 
	책을 대출하기 위한 코드입니다.
*/
void borrowBook() {

	int searchType;

	printf("\n===== 대출 검색 방법 선택 =====\n");
	printf("1. 도서 번호로 검색\n");
	printf("2. 도서 제목으로 검색\n");
	printf("3. 저자 이름으로 검색\n");
	printf("선택: ");

	scanf("%d", &searchType);
	getchar(); 

	int found = 0;

	if (searchType == 1)
	{
		int id;
		printf("대출할 도서 번호 : ");
		scanf("%d", &id);

		for (int i = 0; i < bookCount; i++)
		{
			if (library[i].id == id) {
				found = 1;
				if (library[i].isBorrowed)
				{
					printf("도서 '%s' 는 이미 대출 중입니다. \n", library[i].title);
				}
				else {
					library[i].isBorrowed = 1;
					strcpy(library[i].borrowor.id, currentUser->id);
					strcpy(library[i].borrowor.name, currentUser->name);
					strcpy(library[i].borrowor.rank, currentUser->rank);
					strcpy(library[i].borrowor.RelationShip.id, currentUser->RelationShip.id);
					printf("도서 '%s' 가 대출되었습니다. \n", library[i].title);

				} break;
			}
		}
	}
	else if (searchType == 2 || searchType == 3) {

		char query[100];
		printf(searchType == 2 ? "대출할 도서 제목: " : "대출할 저자 이름: ");

		fgets(query, sizeof(query), stdin);

		removeNewLine(query);

		int candidates[100];
		int candidateCount = 0;



		for (int i = 0; i < bookCount; i++)
		{
			if ((searchType == 2 && strstr(library[i].title, query) != NULL) ||
				(searchType == 3 && strstr(library[i].author, query != NULL)))
			{

				candidates[candidateCount++] = i;
				printf("[%d] 도서 번호: %d\t 제목: %s\t 저자: %s\t 대출 여부: %s\n",
					candidateCount, library[i].id, library[i].title, library[i].author,
					library[i].isBorrowed ? "대출 중" : "대출 가능");
			}
		}

		if (candidateCount == 0)
		{
			printf("검색 조건에 해당하는 도서를 찾을 수 없습니다. \n");
			return;
		}


		int selection;
		printf("\n대출할 도서의 번호를 선택하세요 (1~%d): ", candidateCount);
		scanf("%d", &selection);

		if (selection < 1 || selection > candidateCount)
		{
			printf("\n잘못된 선택입니다. \n");
			return;
		}

		int selectedIndex = candidates[selection - 1];
		if (library[selectedIndex].isBorrowed)
		{
			printf("도서 '%s'는 이미 대출 중입니다.\n", library[selectedIndex].title);
		}
		else {
			// 책 대출 성공
			library[selectedIndex].isBorrowed = 1; 

			strcpy(library[selectedIndex].borrowor.id, currentUser->id);
			strcpy(library[selectedIndex].borrowor.name, currentUser->name);
			strcpy(library[selectedIndex].borrowor.rank, currentUser->rank);
			strcpy(library[selectedIndex].borrowor.RelationShip.id, currentUser->RelationShip.id);

			printf("도서 '%s' 가 대출되었습니다. \n", library[selectedIndex].title);
		}
	}
	else
	{
		printf("잘못된 선택입니다. \n");
	}
}



/** 
	책을 반납하기 위해 제작한 함수입니다.
*/
void returnBooks() {

	int searchType;

	printf("\n===== 대출 검색 방법 선택 =====\n");
	printf("1. 도서 번호로 검색\n");
	printf("2. 도서 제목으로 검색\n");
	printf("3. 저자 이름으로 검색\n");
	printf("선택: ");

	scanf("%d", &searchType);

	getchar();

	int found = 0;

	if (searchType == 1)
	{
		int id;
		printf("반납할 도서 번호 : ");
		scanf("%d", &id);

		for (int i = 0; i < bookCount; i++)
		{
			if (library[i].id == id) {
				
				found = 1;
				if (strcmp(library[i].borrowor.id, currentUser->id) != 0) {
					printf("본인만 반납하실 수 있습니다.\n");
				}
				else {

					if (!library[i].isBorrowed)
					{
						printf("도서 '%s' 는 이미 반납되었습니다. \n", library[i].title);
					}
					else {
						library[i].isBorrowed = 0;

						printf("도서 '%s' 가 반납되었습니다. \n", library[i].title);

					}
				} break;
			}
		}
	}
	else if (searchType == 2 || searchType == 3) {

		char query[100];
		printf(searchType == 2 ? "반납할 도서 제목: " : "반납할 도서의 저자 이름: ");

		fgets(query, sizeof(query), stdin);

		removeNewLine(query);

		int candidates[100];
		int candidateCount = 0;

		for (int i = 0; i < bookCount; i++)
		{
			if ((searchType == 2 && strstr(library[i].title, query) != NULL) ||
				(searchType == 3 && strstr(library[i].author, query != NULL)))
			{

				candidates[candidateCount++] = i;
				printf("[%d] 도서 번호: %d\t 제목: %s\t 저자: %s\t 대출 여부: %s\n",
					candidateCount, library[i].id, library[i].title, library[i].author,
					library[i].isBorrowed ? "대출 중" : "대출 가능");
			}
		}

		if (candidateCount == 0)
		{
			printf("검색 조건에 해당하는 도서를 찾을 수 없습니다. \n");
			return;
		}


		int selection;
		printf("반납할 도서의 번호를 선택하세요 (1~%d): ", candidateCount);
		scanf("%d", &selection);

		if (selection < 1 || selection > candidateCount)
		{
			printf("잘못된 선택입니다. \n");
			return;
		}

		int selectedIndex = candidates[selection - 1];
		if (!library[selectedIndex].isBorrowed)
		{
			printf("도서 '%s' 는 이미 반납되었습니다. \n", library[selectedIndex].title);
		}
		else {

			if (strcmp(library[selectedIndex].borrowor.id, currentUser->id) != 0) {
				printf("본인만 반납하실 수 있습니다.\n"); // 본인확인
			}

			else {
				library[selectedIndex].isBorrowed = 0;
				printf("도서 '%s' 가 반납되었습니다. \n", library[selectedIndex].title);
			}
		}
	}
	else
	{
		printf("잘못된 선택입니다. \n");
	}
}


// 도서관에 소장된 도서 수 표시
void displayBookCount() {
	printf("도서관에 소장된 도서 수: %d권\n", bookCount);
}


// 도서관 데이터 초기화 (초기 메모리 설정)
void initializeLibrary() {
	library = (Book*)malloc(maxBooks * sizeof(Book));
	if (library == NULL) {
		printf("메모리 할당 실패\n");
		exit(1);
	}

	for (int i = 0; i < maxBooks; i++) {
		library[i].isBorrowed = 0;
		memset(&library[i].borrowor, 0, sizeof(Soilder));
		memset(&library[i].registor, 0, sizeof(Soilder));
	}
}


// 메모리 초기화
void freeMemory()
{
	free(library);
	free(manager);
	
	for (int i = 0; i < ((sizeof(user) + 1) / sizeof(Soilder*)); i++)  // 부동 소수점 연산 관련 대비
	{
		if (user[i] == NULL)
		{
			break; // nullPointerException 대비, 부동 소수점 연산 관련 대비
		}
		free(user[i]);
	}

	free(user);

}

void registerUser(Soilder* newUser) {

	Soilder** temp = (Soilder**)realloc(user, (soilderCount + 1) * sizeof(Soilder*));
	if (temp == NULL) {
		printf("메모리 재할당 실패\n");
		freeMemory();
		exit(1);
	}
	user = temp;

	user[soilderCount] = (Soilder*)malloc(sizeof(Soilder));
	if (user[soilderCount] == NULL) {
		printf("메모리 할당 실패\n");
		freeMemory();
		exit(1);
	}

	strcpy(user[soilderCount]->id, newUser->id);
	strcpy(user[soilderCount]->name, newUser->name);
	strcpy(user[soilderCount]->rank, newUser->rank);
	strcpy(user[soilderCount]->RelationShip.id, newUser->RelationShip.id);

	soilderCount++;
}

void registerUserWizard() {

	Soilder* soilder = (Soilder*) malloc (sizeof(soilder));

	getchar();
	printf("\n본인의 성함을 입력하세요 -> ");
	fgets(soilder->name, sizeof(soilder->name), stdin);
	removeNewLine(soilder->name);


	printf("본인의 계급을 입력하여 주십시오 -> ");
	fgets(soilder->rank, sizeof(soilder->rank), stdin);
	removeNewLine(soilder->rank);

	printf("본인의 군번을 입력하여 주십시오 -> ");
	fgets(soilder->id, sizeof(soilder->id), stdin);
	removeNewLine(soilder->id);

	printf("본인의 소속 부대의 통상명칭을 입력하여 주십시오 -> ");
	fgets(soilder->RelationShip.id, sizeof(soilder->RelationShip.id), stdin);
	removeNewLine(soilder->RelationShip.id);

	registerUser(soilder);


}

void loginUserWizard() {

	char id[240];


	while (1)
	{
		getchar();

		printf("\n 로그인하실 군번을 입력하여 주세요 -> ");
		fgets(id, sizeof(id), stdin);
		removeNewLine(id);
		if (loginUser(id)) {
			continue;
		}
		printf("\n로그인 되었습니다.");
		break;

	}

	
}
void setManager() {


	// 초기 설정
	Soilder* soilder = (Soilder*)malloc(sizeof(Soilder));

	printf("초기 설정입니다. \n");

	printf("담당관 이름을 입력하여 주십시오. ");
	fgets(soilder->name, sizeof(soilder->name), stdin);
	removeNewLine(soilder->name);

	printf("담당관 계급을 입력하여 주십시오. ");
	fgets(soilder->rank, sizeof(soilder->rank), stdin);
	removeNewLine(soilder->rank);

	printf("담당관 군번을 입력하여 주십시오. ");
	fgets(soilder->id, sizeof(soilder->id), stdin);
	removeNewLine(soilder->id);

	printf("담당관 소속 부대의 통상명칭을 입력하여 주십시오. ");
	fgets(soilder->RelationShip.id, sizeof(soilder->RelationShip.id), stdin);
	removeNewLine(soilder->RelationShip.id);

	manager = soilder;
	registerUser(soilder);

	currentUser = manager;
}


int loginUser(char* id) {
	currentUser = (Soilder*)malloc(sizeof(Soilder));

	if (currentUser == NULL)
	{
		printf("Failed to Allocate Memory");
		freeMemory();
		exit(1);
	}
	for (int i = 0; i < soilderCount; i++)
	{
		if (!strcmp(user[i]->id, id))
		{
			currentUser = user[i];
			return 0; // 성공
		}
	}
	// 만약 맞는 id가 없을 경우
	printf("로그인에 실패하였습니다. 맞는 군번이 없습니다.");
	return 1; ///실패

}

int main() {
	int choice;



	setManager();
	initializeLibrary();

	while (1)
	{

		printf("\n%s부대 도서관 담당관 : %s %s [%s]", manager->RelationShip.id, manager->rank, manager->name, manager->id);
		printf("\n사용자 : %s 부대 %s %s [%s]", currentUser->RelationShip.id, currentUser->rank, currentUser->name, currentUser->id);
		printf("\n ===== 도서 관리 프로그램 ===== \n");
		printf("1. 새로운 도서 추가 \n");
		printf("2. 도서 대출 신청 \n");
		printf("3. 도서관이 소장한 도서의 수 표시 \n");
		printf("4. 도서관 보유 도서 목록 보기 \n");
		printf("5. 도서 반납 신청 \n");
		printf("6. 회원가입\n");
		printf("7. 로그인\n");
		printf("0. 종료\n");

		printf("선택 : ");

		if (scanf("%d", &choice) != 1)
		{
			printf("잘못된 입력입니다. \n");
			while (getchar() != '\n');
			continue;
		}

		switch (choice)
		{
		case 1:
			addBook();
			break;
		case 2:
			borrowBook();
			break;	
		case 3:
			displayBookCount();
			break;
		case 4:
			displayBooks();
			break;
		case 5:
			returnBooks();
			break;
		case 6:
			registerUserWizard();
			break;
		case 7:
			loginUserWizard();
			break;
		case 0:
			printf("프로그램을 종료합니다. \n");
			freeMemory();
			return 0;
		default:
			printf("잘못된 입력입니다. 다시 시도하세요 \n");
		}
	}
}
