/*
 * solution.c
 *
 *  Created on: 2016年3月28日
 *      Author: wengle
 */

int maxProduct(char** words, int wordsSize) {
    // int result = 0, current = 0, i = 0, j = 0, flag = 0;
    // char *temp;
    // for(i = 0; i < wordsSize; i++){
    //     for(j = i+1; j < wordsSize; j++){
    //         for(temp = words[i]; *temp != '\0'; temp++){
    //             if(strchr(words[j], *temp)){
    //                 flag = 1;
    //                 break;
    //             }
    //         }
    //         if(flag == 0){
    //             current = strlen(words[i])*strlen(words[j]);
    //             if(current > result){
    //                 result = current;
    //             }
    //         }
    //         flag = 0;
    //     }
    // }
    int result = 0, i = 0, j = 0;
    int *mask = (int*)calloc(wordsSize, sizeof(int));
    //以后都不要使用malloc来创建数组了
    // int *mask = (int*)malloc(sizeof(int)*wordsSize);
    char *temp;
    for(i = 0; i < wordsSize; i++){
        for(temp = words[i]; *temp != '\0'; temp++){
            mask[i] |= 1 << (*temp - 'a');
        }
        for(j = 0; j < i; j++){
            if(!(mask[i] & mask[j])){
                if(result < (strlen(words[i])*strlen(words[j]))){
                    result = (int)(strlen(words[i])*strlen(words[j]));
                }
            }
        }
    }
    return result;
}
