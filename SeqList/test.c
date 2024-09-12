#include "SeqList.h"

int main() {
    SeqList* seq_list = SeqList_init();
    for (int i = 0; i < 100; i++) {
        int flag = insert_SeqList(seq_list, i);
    }
    SeqList_print(seq_list);

    int flag = insert_SeqList_by_index(seq_list, 3, 1);
    SeqList_print(seq_list);

    flag = delete_SeqList_by_index(seq_list, 3);
    SeqList_print(seq_list);

    flag = update_SeqList_by_index(seq_list, 100, 100);
    printf("%d\n", flag);
    SeqList_print(seq_list);

    int p;
    flag = get_SeqList_by_index(seq_list, 2, &p);
    printf("%d %d\n", flag, p);

    system("pause");
    return 0;
}