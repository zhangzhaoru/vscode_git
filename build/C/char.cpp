/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-16 17:17:51
 * @LastTime: 2020-03-16 17:18:27
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\char.cpp
 * @Description: 
 */

class Solution {
public:
	void replaceSpace(char *str,int length) {
        int blankNumber =0;
        int oldstringlen;
        for(oldstringlen = 0;str[oldstringlen]!='\0';oldstringlen++){
            if(str[oldstringlen]==' ')
                blankNumber++;
        }
        int newstringlen = oldstringlen + blankNumber*2;
        if(newstringlen>length)
            return;
        str[newstringlen] = '\0';
        int pointer1 = newstringlen-1;
        int pointer2 = oldstringlen-1;
        while(pointer2>=0 && pointer1>pointer2){
            if(str[pointer2] ==' '){
                  str[pointer1--] = '0';
                  str[pointer1--] = '2';
                  str[pointer1--] = '%';
            }
            else{
                str[pointer1] = str[pointer2];
                pointer1--;
                
            }
            pointer2--;
        }
	}
};
