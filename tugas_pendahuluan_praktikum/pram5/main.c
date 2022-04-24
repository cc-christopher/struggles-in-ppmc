void checkPalindrome(char kata_yg_dicek[], int index){
    int len = strlen(kata_yg_dicek) - (index + 1);
    if (kata_yg_dicek[index] == kata_yg_dicek[len]){
        if (index + 1 == len){
        printf("Palindrom\n");
        return;
        }
        checkPalindrome(kata_yg_dicek, index+1);
    }
    else{
        printf("Bukan palindrom\n");
    }
}

int main ()
{
    checkPalindrome("ama", 0);
    return 0;
}
