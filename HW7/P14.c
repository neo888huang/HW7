

/*P14
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* fptr = NULL;    // 宣告指向檔案的指標，初始化為 NULL
    char ch;              // 宣告字元變數 ch，用來接收讀取的字元
    int count = 0;        // 宣告整數變數 count，用來計算總字元數

    // 使用 fopen_s 開啟檔案
    if (fopen_s(&fptr, "welcome.txt", "r") == 0) // fopen_s 成功返回 0
    {
        while ((ch = getc(fptr)) != EOF) // 判斷是否到達檔尾
        {
            printf("%c", ch);  // 一次印出一個字元
            count++;           // 計算字元數
        }
        fclose(fptr);          // 關閉檔案
        printf("\n總共有%d個字元\n", count); // 輸出總字元數
    }
    else
    {
        printf("檔案開啟失敗!\n"); // 如果檔案開啟失敗，提示錯誤訊息
    }

    system("pause"); // 暫停程式運行
    return 0;
}
*/
/*P15
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* fptr1 = NULL;    // 宣告指向檔案的指標 fptr1
    FILE* fptr2 = NULL;    // 宣告指向檔案的指標 fptr2
    char ch;               // 宣告字元變數 ch，用來接收讀取的字元

    // 使用 fopen_s 開啟檔案
    if (fopen_s(&fptr1, "welcome.txt", "r") == 0 && fopen_s(&fptr2, "output.txt", "w") == 0)
    {
        while ((ch = getc(fptr1)) != EOF) // 判斷是否到達檔尾
        {
            putc(ch, fptr2);  // 將字元 ch 寫入到 fptr2 所指向的檔案
        }
        fclose(fptr1);        // 關閉 fptr1 所指向的檔案
        fclose(fptr2);        // 關閉 fptr2 所指向的檔案
        printf("檔案拷貝完成!!\n");
    }
    else
    {
        printf("檔案開啟失敗!!\n"); // 如果任一檔案開啟失敗，提示錯誤訊息
    }

    system("pause");          // 暫停程式運行
    return 0;
}
*/

/*P16
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ENTER 13  // 定義 ENTER 鍵的 ASCII 值
#define MAX 80    // 定義最大輸入字元數

int main(void)
{
    FILE* fptr = NULL;      // 宣告指向檔案的指標
    char str[MAX], ch;      // 宣告字元陣列 str 用來儲存輸入的字串
    int i = 0;              // 用來追蹤字元陣列索引

    // 使用 fopen_s 開啟檔案，模式為附加（"a"）
    if (fopen_s(&fptr, "output.txt", "a") == 0)
    {
        printf("請輸入字串，按 ENTER 鍵結束輸入:\n");
        while ((ch = _getche()) != ENTER && i < MAX - 1) // 按下的鍵不是 ENTER，且未超過最大長度
        {
            str[i++] = ch;  // 將輸入字元存入陣列
        }
        str[i] = '\0';      // 為字串加上結尾符號

        putc('\n', fptr);   // 寫入換行符號到檔案
        fwrite(str, sizeof(char), i, fptr); // 將字串寫入檔案
        fclose(fptr);       // 關閉檔案
        printf("\n檔案附加完成!!!\n");
    }
    else
    {
        printf("檔案開啟失敗!!\n"); // 如果檔案開啟失敗，提示錯誤訊息
    }

    system("pause"); // 暫停程式運行
    return 0;
}*/

/* 使用 fread() 函數讀取檔案內容 */

/*P17
#include <stdio.h>
#include <stdlib.h>
#define MAX 80

int main(void)
{
    FILE* fptr = NULL;
    char str[MAX];
    int bytes;

    // 使用 fopen_s 開啟檔案
    if (fopen_s(&fptr, "output.txt", "r") != 0) {
        printf("無法開啟檔案！\n");
        return 1; // 返回錯誤代碼
    }

    while (!feof(fptr)) // 如果還沒讀到檔尾
    {
        bytes = fread(str, sizeof(char), MAX - 1, fptr);
        str[bytes] = '\0'; // 確保字串結束
        printf("%s\n", str); // 印出檔案內容
    }

    fclose(fptr); // 關閉檔案
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

    // 使用 fopen_s 開啟檔案
    if (fopen_s(&in, "welcome.txt", "r") != 0) {
        printf("無法開啟檔案 welcome.txt！\n");
        return 1; // 返回錯誤代碼
    }

    if (fopen_s(&out, "output.txt", "w") != 0) {
        printf("無法開啟檔案 output.txt！\n");
        fclose(in); // 關閉已開啟的檔案
        return 1; // 返回錯誤代碼
    }

    // 修正迴圈邏輯，改用 fscanf_s 的回傳值進行檢查
    while (fscanf_s(in, "%99s", str, (unsigned)_countof(str)) == 1) {
        fprintf(out, "%s\n", str); // 寫入檔案
    }

    fclose(in); // 關閉輸入檔案
    fclose(out); // 關閉輸出檔案
    system("pause");
    return 0;
}
