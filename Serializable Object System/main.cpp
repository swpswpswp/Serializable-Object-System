#include <iostream>
#include "json_value.h"
using namespace std;

void testSerialization() {
    cout << "========== 序列化测试 ==========" << endl;

    // 1. null
    JsonNull v1;
    cout << "1. null: " << v1.serialize() << " (期望: null)" << endl;

    // 2. bool true
    JsonBool v2(true);
    cout << "2. true: " << v2.serialize() << " (期望: true)" << endl;

    // 3. bool false
    JsonBool v3(false);
    cout << "3. false: " << v3.serialize() << " (期望: false)" << endl;

    // 4. 整数
    JsonNumber v4(42);
    cout << "4. 整数: " << v4.serialize() << " (期望: 42)" << endl;

    // 5. 负数
    JsonNumber v5(-10);
    cout << "5. 负数: " << v5.serialize() << " (期望: -10)" << endl;

    // 6. 小数
    JsonNumber v6(3.14159);
    cout << "6. 小数: " << v6.serialize() << " (期望: 3.14159)" << endl;

    // 7. 空字符串
    JsonString v7("");
    cout << "7. 空字符串: " << v7.serialize() << " (期望: \"\")" << endl;

    // 8. 普通字符串
    JsonString v8("hello");
    cout << "8. 普通字符串: " << v8.serialize() << " (期望: \"hello\")" << endl;

    // 9. 带引号的字符串
    JsonString v9("he said \"hi\"");
    cout << "9. 带引号: " << v9.serialize() << " (期望: \"he said \\\"hi\\\"\")" << endl;

    // 10. 空数组
    JsonArray v10;
    cout << "10. 空数组: " << v10.serialize() << " (期望: [])" << endl;

    // 11. 单元素数组
    JsonArray v11;
    v11.add(new JsonNumber(1));
    cout << "11. 单元素数组: " << v11.serialize() << " (期望: [1])" << endl;

    // 12. 多元素数组
    JsonArray v12;
    v12.add(new JsonNumber(1));
    v12.add(new JsonNumber(2));
    v12.add(new JsonNumber(3));
    cout << "12. 多元素数组: " << v12.serialize() << " (期望: [1,2,3])" << endl;

    // 13. 混合类型数组
    JsonArray v13;
    v13.add(new JsonNumber(1));
    v13.add(new JsonString("hello"));
    v13.add(new JsonBool(true));
    v13.add(new JsonNull());
    cout << "13. 混合数组: " << v13.serialize() << " (期望: [1,\"hello\",true,null])" << endl;

    // 14. 空对象
    JsonObject v14;
    cout << "14. 空对象: " << v14.serialize() << " (期望: {})" << endl;

    // 15. 单键值对
    JsonObject v15;
    v15.set("k", new JsonString("v"));
    cout << "15. 单键值对: " << v15.serialize() << " (期望: {\"k\":\"v\"})" << endl;

    // 16. 多键值对
    JsonObject v16;
    v16.set("a", new JsonNumber(1));
    v16.set("b", new JsonNumber(2));
    cout << "16. 多键值对: " << v16.serialize() << " (期望: {\"a\":1,\"b\":2})" << endl;

    // 17. 数组嵌套数组
    JsonArray v17;
    JsonArray* inner1 = new JsonArray();
    inner1->add(new JsonNumber(1));
    inner1->add(new JsonNumber(2));
    JsonArray* inner2 = new JsonArray();
    inner2->add(new JsonNumber(3));
    inner2->add(new JsonNumber(4));
    v17.add(inner1);
    v17.add(inner2);
    cout << "17. 嵌套数组: " << v17.serialize() << " (期望: [[1,2],[3,4]])" << endl;

    // 18. 数组嵌套对象
    JsonArray v18;
    JsonObject* user1 = new JsonObject();
    user1->set("name", new JsonString("张三"));
    JsonObject* user2 = new JsonObject();
    user2->set("name", new JsonString("李四"));
    v18.add(user1);
    v18.add(user2);
    cout << "18. 数组嵌套对象: " << v18.serialize() << " (期望: [{\"name\":\"张三\"},{\"name\":\"李四\"}])" << endl;

    // 19. 对象嵌套对象
    JsonObject v19;
    JsonObject* addr = new JsonObject();
    addr->set("city", new JsonString("北京"));
    addr->set("code", new JsonNumber(100000));
    v19.set("address", addr);
    cout << "19. 对象嵌套对象: " << v19.serialize() << " (期望: {\"address\":{\"city\":\"北京\",\"code\":100000}})" << endl;

    // 20. 对象嵌套数组
    JsonObject v20;
    JsonArray* scores = new JsonArray();
    scores->add(new JsonNumber(90));
    scores->add(new JsonNumber(95));
    scores->add(new JsonNumber(88));
    v20.set("scores", scores);
    v20.set("name", new JsonString("张三"));
    cout << "20. 对象嵌套数组: " << v20.serialize() << " (期望: {\"name\":\"张三\",\"scores\":[90,95,88]})" << endl;
}

int main() {
    testSerialization();
    return 0;
}