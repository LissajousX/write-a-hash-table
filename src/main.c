#include "hash_table.h"
#include <stdio.h>

int main() {
    printf("Creating hash table...\n");
    ht_hash_table* ht = ht_new();
    printf("size:%d\n",ht->size);

    // 插入多个键值对
    printf("Inserting key-value pairs...\n");
    ht_insert(ht, "name", "Alice");
    ht_insert(ht, "age", "25");
    ht_insert(ht, "city", "New York");
    ht_insert(ht, "job", "Engineer");
    ht_insert(ht, "company", "TechCorp");

    // 检查插入是否成功
    printf("Searching key-value pairs...\n");
    printf("name: %s\n", ht_search(ht, "name"));
    printf("age: %s\n", ht_search(ht, "age"));
    printf("city: %s\n", ht_search(ht, "city"));
    printf("job: %s\n", ht_search(ht, "job"));
    printf("company: %s\n", ht_search(ht, "company"));

    // 删除部分键值对
    printf("Deleting key-value pairs...\n");
    ht_delete(ht, "age");
    ht_delete(ht, "city");

    // 再次搜索，确保删除成功
    printf("Search after deletion...\n");
    printf("age: %s\n", ht_search(ht, "age"));   // 应返回 NULL
    printf("city: %s\n", ht_search(ht, "city")); // 应返回 NULL
    printf("name: %s\n", ht_search(ht, "name")); // 应仍然存在

    // 大量插入和删除
    printf("Stress testing with large number of insertions and deletions...\n");
    for (int i = 0; i < 5000; i++) {
        char key[20];
        char value[20];
        sprintf(key, "key_%d", i);
        sprintf(value, "value_%d", i);
        ht_insert(ht, key, value);
    }

    for (int i = 0; i < 5000; i++) {
        char key[20];
        sprintf(key, "key_%d", i);
        if (i % 2 == 0) {
            ht_delete(ht, key); // 删除偶数编号的键
        }
    }

    // 验证结果
    printf("Validating remaining keys...\n");
    for (int i = 0; i < 5000; i++) {
        char key[20];
        sprintf(key, "key_%d", i);
        const char* result = ht_search(ht, key);
        // if(result) continue;
        if (i % 2 == 0) {
            printf("%s: %s (should be NULL)\n", key, result); // 偶数键应为 NULL
        } else {
            printf("%s: %s (should exist)\n", key, result); // 奇数键应存在
        }
    }

    // 销毁哈希表
    printf("Destroying hash table...\n");
    ht_del_hash_table(ht);

    return 0;
}
