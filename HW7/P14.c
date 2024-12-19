

/*P14
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* fptr = NULL;    // �ŧi���V�ɮת����СA��l�Ƭ� NULL
    char ch;              // �ŧi�r���ܼ� ch�A�Ψӱ���Ū�����r��
    int count = 0;        // �ŧi����ܼ� count�A�Ψӭp���`�r����

    // �ϥ� fopen_s �}���ɮ�
    if (fopen_s(&fptr, "welcome.txt", "r") == 0) // fopen_s ���\��^ 0
    {
        while ((ch = getc(fptr)) != EOF) // �P�_�O�_��F�ɧ�
        {
            printf("%c", ch);  // �@���L�X�@�Ӧr��
            count++;           // �p��r����
        }
        fclose(fptr);          // �����ɮ�
        printf("\n�`�@��%d�Ӧr��\n", count); // ��X�`�r����
    }
    else
    {
        printf("�ɮ׶}�ҥ���!\n"); // �p�G�ɮ׶}�ҥ��ѡA���ܿ��~�T��
    }

    system("pause"); // �Ȱ��{���B��
    return 0;
}
*/
/*P15
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* fptr1 = NULL;    // �ŧi���V�ɮת����� fptr1
    FILE* fptr2 = NULL;    // �ŧi���V�ɮת����� fptr2
    char ch;               // �ŧi�r���ܼ� ch�A�Ψӱ���Ū�����r��

    // �ϥ� fopen_s �}���ɮ�
    if (fopen_s(&fptr1, "welcome.txt", "r") == 0 && fopen_s(&fptr2, "output.txt", "w") == 0)
    {
        while ((ch = getc(fptr1)) != EOF) // �P�_�O�_��F�ɧ�
        {
            putc(ch, fptr2);  // �N�r�� ch �g�J�� fptr2 �ҫ��V���ɮ�
        }
        fclose(fptr1);        // ���� fptr1 �ҫ��V���ɮ�
        fclose(fptr2);        // ���� fptr2 �ҫ��V���ɮ�
        printf("�ɮ׫�������!!\n");
    }
    else
    {
        printf("�ɮ׶}�ҥ���!!\n"); // �p�G���@�ɮ׶}�ҥ��ѡA���ܿ��~�T��
    }

    system("pause");          // �Ȱ��{���B��
    return 0;
}
*/

/*P16
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ENTER 13  // �w�q ENTER �䪺 ASCII ��
#define MAX 80    // �w�q�̤j��J�r����

int main(void)
{
    FILE* fptr = NULL;      // �ŧi���V�ɮת�����
    char str[MAX], ch;      // �ŧi�r���}�C str �Ψ��x�s��J���r��
    int i = 0;              // �ΨӰl�ܦr���}�C����

    // �ϥ� fopen_s �}���ɮסA�Ҧ������[�]"a"�^
    if (fopen_s(&fptr, "output.txt", "a") == 0)
    {
        printf("�п�J�r��A�� ENTER �䵲����J:\n");
        while ((ch = _getche()) != ENTER && i < MAX - 1) // ���U���䤣�O ENTER�A�B���W�L�̤j����
        {
            str[i++] = ch;  // �N��J�r���s�J�}�C
        }
        str[i] = '\0';      // ���r��[�W�����Ÿ�

        putc('\n', fptr);   // �g�J����Ÿ����ɮ�
        fwrite(str, sizeof(char), i, fptr); // �N�r��g�J�ɮ�
        fclose(fptr);       // �����ɮ�
        printf("\n�ɮת��[����!!!\n");
    }
    else
    {
        printf("�ɮ׶}�ҥ���!!\n"); // �p�G�ɮ׶}�ҥ��ѡA���ܿ��~�T��
    }

    system("pause"); // �Ȱ��{���B��
    return 0;
}*/

/* �ϥ� fread() ���Ū���ɮפ��e */

/*P17
#include <stdio.h>
#include <stdlib.h>
#define MAX 80

int main(void)
{
    FILE* fptr = NULL;
    char str[MAX];
    int bytes;

    // �ϥ� fopen_s �}���ɮ�
    if (fopen_s(&fptr, "output.txt", "r") != 0) {
        printf("�L�k�}���ɮסI\n");
        return 1; // ��^���~�N�X
    }

    while (!feof(fptr)) // �p�G�٨SŪ���ɧ�
    {
        bytes = fread(str, sizeof(char), MAX - 1, fptr);
        str[bytes] = '\0'; // �T�O�r�굲��
        printf("%s\n", str); // �L�X�ɮפ��e
    }

    fclose(fptr); // �����ɮ�
    system("pause");
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* in = NULL, * out = NULL;
    char str[100];

    // �ϥ� fopen_s �}���ɮ�
    if (fopen_s(&in, "welcome.txt", "r") != 0) {
        printf("�L�k�}���ɮ� welcome.txt�I\n");
        return 1; // ��^���~�N�X
    }

    if (fopen_s(&out, "output.txt", "w") != 0) {
        printf("�L�k�}���ɮ� output.txt�I\n");
        fclose(in); // �����w�}�Ҫ��ɮ�
        return 1; // ��^���~�N�X
    }

    // �ץ��j���޿�A��� fscanf_s ���^�ǭȶi���ˬd
    while (fscanf_s(in, "%99s", str, (unsigned)_countof(str)) == 1) {
        fprintf(out, "%s\n", str); // �g�J�ɮ�
    }

    fclose(in); // ������J�ɮ�
    fclose(out); // ������X�ɮ�
    system("pause");
    return 0;
}
