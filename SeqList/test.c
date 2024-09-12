#include "SeqList.h"

int main() {
    SeqList* seq_list = SeqList_init();
    for (int i = 0; i < 100; i++) {
        int flag = insert_SeqList(seq_list, i);
    }
    SeqList_print(seq_list);


    system("pause");
    return 0;
}