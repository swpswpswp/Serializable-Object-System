#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class JsonValue 
{
public:
	virtual string serialize() const = 0;
	virtual ~JsonValue() {}
};

class JsonObject :public JsonValue
{
private:
	map<string, JsonValue*> values; 
public:
	void set(const string& key, JsonValue* val);
	JsonValue* get(const string& key) const;
	bool hasKey(const string& key) const;
	string serialize() const override;
	~JsonObject();  // 需要释放所有值
};

class JsonArray :public JsonValue
{
private:
	vector<JsonValue*> values;
public:
	void add(JsonValue* val);
	JsonValue* get(int index) const;
	int size() const;
	string serialize() const override;
	~JsonArray();  // 需要释放所有元素
};

class JsonString :public JsonValue
{
private:
	string value;
public:
	JsonString(const string& val) :value(val) {};
	string serialize() const override;
};

class JsonNumber :public JsonValue
{
private:
	double value;
public:
	JsonNumber(double val) :value(val) {};
	string serialize() const override;
};

class JsonBool :public JsonValue
{
private:
	bool value;
public:
	JsonBool(bool val) :value(val) {};
	string serialize() const override;
};

class JsonNull :public JsonValue
{
public:
	string serialize() const override;
};