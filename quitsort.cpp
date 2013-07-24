/* 
 * File:   main.cpp
 * Author: jawinton
 *
 * Created on 2010��9��2��, ����7:55
 */

#include <cstdlib>

using namespace std;

#include <stdio.h>

static void qsort_swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void qsort(int *base, int nmemb)
{
	int *begin_stack[10];
	int *end_stack[10];
	int *begin;
	int *end;
	int *seg1;
	int *seg2;
	int *seg2p;
	int loop;
	unsigned int offset;

	/* ʹ��ջ�����ǳ����ĵݹ�ʵ�� */
	begin_stack[0] = base;	//	��ʼԪ��λ��ջ����ջ
	end_stack[0]   = base + (nmemb - 1) ;	//	����λ��ջ����ջ

	for (loop = 0; loop >= 0; --loop) {
		begin = begin_stack[loop];	//	��ʼλ�ó�ջ
		end   = end_stack[loop];	//	����λ�ó�ջ

		while (begin < end) {//����λ�ô�С�Ƚ�
			offset = (end - begin) >> 1;	//	ȡ�м�λ��

			qsort_swap(begin, begin + offset);	//	������ʼ���м��λ�õ���ֵ

			seg1 = begin;
			seg2 = end;

			while (1) {
                                //�����ߵ���ֵ

				for (; seg1 < seg2 && *begin < *seg1 ; seg1 += 1);

				for (; seg2 >= seg1 && *seg2 > *begin; seg2 -= 1);

				if (seg1 >= seg2)
					break;

				qsort_swap(seg1, seg2);
			}

			qsort_swap(begin, seg2);

			seg2p = seg2;

			if ((seg2p - begin) <= (end - seg2p)) {
				if (seg2p < end) {	//	�Ҳ���ջ
					begin_stack[loop] = seg2p + 1;
					end_stack[loop++] = end;
				}
				end = seg2p;
			} else {
				if (seg2p > begin) {	// �����ջ
					begin_stack[loop] = begin;
					end_stack[loop++] = seg2p - 1;
				}	//	end if
				begin = seg2p;
			}	//	end if
		}	//	end while
	}	//	end for

}
//int main(int argc, char *argv[])
//{
//    int m = 3,n=5;
//    qsort_swap(&m,&n);
//    printf("%d %d",m,n);
//	int a[10] = {14, 5, 7, 8, 2, 4, 55, 3};
//	int i;
//	qsort(a, 8);
//	for (i = 0; i < 8;i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}


