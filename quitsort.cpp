/* 
 * File:   main.cpp
 * Author: jawinton
 *
 * Created on 2010年9月2日, 下午7:55
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

	/* 使用栈而不是常见的递归实现 */
	begin_stack[0] = base;	//	开始元素位置栈，入栈
	end_stack[0]   = base + (nmemb - 1) ;	//	结束位置栈，入栈

	for (loop = 0; loop >= 0; --loop) {
		begin = begin_stack[loop];	//	开始位置出栈
		end   = end_stack[loop];	//	结束位置出栈

		while (begin < end) {//两者位置大小比较
			offset = (end - begin) >> 1;	//	取中间位置

			qsort_swap(begin, begin + offset);	//	交换开始和中间的位置的数值

			seg1 = begin;
			seg2 = end;

			while (1) {
                                //当两边的数值

				for (; seg1 < seg2 && *begin < *seg1 ; seg1 += 1);

				for (; seg2 >= seg1 && *seg2 > *begin; seg2 -= 1);

				if (seg1 >= seg2)
					break;

				qsort_swap(seg1, seg2);
			}

			qsort_swap(begin, seg2);

			seg2p = seg2;

			if ((seg2p - begin) <= (end - seg2p)) {
				if (seg2p < end) {	//	右侧入栈
					begin_stack[loop] = seg2p + 1;
					end_stack[loop++] = end;
				}
				end = seg2p;
			} else {
				if (seg2p > begin) {	// 左侧入栈
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


