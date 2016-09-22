#include <stdio.h>
#include <string.h>
#include <malloc.h>



typedef struct Node
{
	int length;
	char word[30];
	struct nodeData *next;
} node; //����ü ����

node *head, *tail;//���Ḯ��Ʈ ����� link ����


void InitialWork();//����Ʈ �ʱ�ȭ
void InputFileData();//������ �ҷ��� ���Ḯ��Ʈ�� �� ����.
void Findnode(node* p);//���� ã�Ƽ� ��ġ�� ���� ���

void main()
{

	InitialWork();
	InputFileData();

	Findnode(head);


}

void InitialWork()
{
	head = (node *)malloc(sizeof(node));//�����޸� �Ҵ�
	tail = head;//ù����� link���� ���� ����.
	head->next = NULL;

}


void InputFileData()
{
	FILE *fp;


	char filename[30];
	printf("�����̸��� �Է��ϼ���(.txt���� �Է��ϼ���): ");
	fflush(stdout);
	scanf("%s",filename);

	fp = fopen(filename, "r");// ���� �̸��� �Է¹޾� �б���� ����

	if(fp==NULL)//������ �������� ���� ��� ���� ��¹�
	{
		perror("�Է��Ͻ� ������ �������� �ʽ��ϴ�. �ٽ� �����Ͻʽÿ�.");

	}

	while(!feof(fp))//������ ���������� ��忡 ������ ����
	{
		fscanf(fp,"%s",tail->word);
		tail ->next = (node *)malloc(sizeof(node));
				tail = tail->next;
				tail->next = NULL;

	}



	fclose(fp);//���� �ݱ�
}

void Findnode(node *p)
{
	char find[30];
	int bool = 0;
	int num = 1;
	int count = 0;


	printf("ã���ô� �ܾ �Է��ϼ���: ");
		fflush(stdout);
		scanf("%s",find);

	while(p-> next != NULL)//��尡 ���������� Ž��

	{if(strcmp(p->word,find)==0){// �����ϴ� ��� ������ �ϳ��� �ø���.
			count ++;
			printf("����Ʈ�� %d��°�� �ֽ��ϴ�.\n",num);
			bool=1;
		}

	num++;//Ž���ϸ鼭 ����� ������ �ϳ��� �߰��Ѵ�.
	p = p->next;

	}

	if(!bool)//�������� �ʴ� ���
	{
		printf("�Է��Ͻ� �ܾ�� �����ϴ�.\n");
	}
	printf("�Է��Ͻ� �ܾ��� �� ������ %d�Դϴ�.\n",count);
}




