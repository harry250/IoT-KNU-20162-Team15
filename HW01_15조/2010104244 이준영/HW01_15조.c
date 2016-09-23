#include <stdio.h>
#include <string.h>
#include <malloc.h>



typedef struct Node
{
	int length;
	char word[30];
	struct nodeData *next;
} node; //구조체 선언

node *head, *tail;//연결리스트 헤더와 link 정의


void InitialWork();//리스트 초기화
void InputFileData();//파일을 불러와 연결리스트에 값 삽입.
void Findnode(node* p);//문자 찾아서 위치와 개수 출력

void main()
{

	InitialWork();
	InputFileData();

	Findnode(head);


}

void InitialWork()
{
	head = (node *)malloc(sizeof(node));//동적메모리 할당
	tail = head;//첫노드의 link값은 헤드와 같다.
	head->next = NULL;

}


void InputFileData()
{
	FILE *fp;


	char filename[30];
	printf("파일이름을 입력하세요(.txt까지 입력하세요): ");
	fflush(stdout);
	scanf("%s",filename);

	fp = fopen(filename, "r");// 파일 이름을 입력받아 읽기모드로 열기

	if(fp==NULL)//파일이 존재하지 않을 경우 에러 출력문
	{
		perror("입력하신 파일은 존재하지 않습니다. 다시 실행하십시오.");

	}

	while(!feof(fp))//파일이 끝날때까지 노드에 데이터 삽입
	{
		fscanf(fp,"%s",tail->word);
		tail ->next = (node *)malloc(sizeof(node));
				tail = tail->next;
				tail->next = NULL;

	}



	fclose(fp);//파일 닫기
}

void Findnode(node *p)
{
	char find[30];
	int bool = 0;
	int num = 1;
	int count = 0;


	printf("찾으시는 단어를 입력하세요: ");
		fflush(stdout);
		scanf("%s",find);

	while(p-> next != NULL)//노드가 끝날때까지 탐색

	{if(strcmp(p->word,find)==0){// 존재하는 경우 개수를 하나씩 늘린다.
			count ++;
			printf("리스트의 %d번째에 있습니다.\n",num);
			bool=1;
		}

	num++;//탐색하면서 노드의 개수를 하나씩 추가한다.
	p = p->next;

	}

	if(!bool)//존재하지 않는 경우
	{
		printf("입력하신 단어는 없습니다.\n");
	}
	printf("입력하신 단어의 총 개수는 %d입니다.\n",count);
}




