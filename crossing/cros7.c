#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 314159

long marge_sort (long a, long b,long *num, long *tmp_num);

int main ()
{
    FILE *fp;
    int ret;
    long ix = 0;
    long count = 0;
    long n;
    long *num;
    long tmp_num[MAX_NUM];

    fp = fopen("./crossing.txt","r");
    if (fp == NULL) {
        printf("ファイルオープンエラー\n");
        return -1;
    }

//決め打ち
//    for (ix = 0; ix < MAX_NUM; ix++) {
//        fscanf(fp, "%ld", &num[ix]);
//    }
    while(( ret = fscanf( fp , "%ld" ,  &n )) != EOF ) {
        num += ix * sizeof(long);
        num = (long *)malloc(sizeof(long));
        num[ix] = n;
        ix++;
    }

    count = marge_sort(0, ix - 1, num, tmp_num);

    fclose(fp);
    printf("count = %ld", count);

    return 0;
}


long marge_sort (long start, long end, long *num, long *tmp_num)
{
    long count = 0;
    long num_num = end - start + 1;
    if (num_num <= 2) { //要素数２以下なら正しい並びにする(再帰なし)
        if (num[start] > num[end]) { //要素が2つあって、前の数のが大きければ入れ替え
            long tmp = num[end];
            num[end] = num[start];
            num[start] = tmp;
            count++;
        } //他の場合はそのまま
    }else{ //要素数2以上なら分割して、さらにマージソートに渡す(再帰)
        long center = 0;
        center = start + (num_num / 2); //2グループに分ける
        count += marge_sort(start, center-1, num, tmp_num); //グループ1をマージソートに渡す
        count += marge_sort(center, end, num, tmp_num); //グループ2をマージソートに渡す
        long iy = 0; //tmp行列のカウント
        long i = 0; //グループ1の要素添字
        long j = 0; //グループ2の要素添字
        long i_max = center - start;
        long j_max = end - center + 1;
        for (iy = 0; iy < num_num; iy++) { //ソートされたグループをマージ
            if (i_max  == i) { //グループ１を出し切ったときグループ2からtmpに代入
                tmp_num[iy] = num[center + j];
                j++;
            } else if (j_max == j){ //グループ2を出し切ったときグループ1からtmpに代入
                tmp_num[iy] = num[start + i];
                i++;
            } else if (num[start + i] < num[center + j]) { //両グループ残ってたら小さい数をtmpに代入
                tmp_num[iy] = num[start + i];
                i++;
            } else { //両グループ残ってたら小さい方の数をtmpに代入 + カウント
                tmp_num[iy] = num[center + j];
                j++;
                count += i_max - 1 - iy + j; //count+= (end - start) - ix - ((end - center + 1) - j);
            }
        }
        if (num_num > MAX_NUM - 1 ) { //最後はここで抜ける
            return count;
        }
        for (iy = 0; iy < num_num; iy++) { //tmp配列からnumへコピー
            num[start + iy] = tmp_num[iy];
        }
    }
    return count;
}
