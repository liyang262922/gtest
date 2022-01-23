#pragma once

#include <regex>

/*
std::regex

std::regex_match 函数模板	正则表达式完全匹配整个字符串序列，如果匹配成功，可以获取捕获组 单次
{
	多种重载模式，
}
std::regex_search  函数模板	在字符串中搜索正则表达式匹配的子串，如果搜索成功，它可以获取捕获组	单次
std::regex_replace 函数模板	多次搜索整个正则表达式（不考虑捕获组），然后替换正则表达式匹配的值 多次替换
std::regex_iterator 类模板	多次重复匹配，不分组，只进行多次匹配整个正则表达式，可获取整个正则表达式的结果 多次匹配
std::regex_token_iterator 类模板 多次匹配正则表达式，可以获取整个正则表达式的结果以及正则表达式的前缀和捕获组 多次匹配

()表示捕获组，捕获组标号按照从左到右的顺序，从1开始

std::string text = "Date:2017-10-10";
std::string pattern = "Date.(\\d{4})-(\\d{2}-(\\d{2}))"
std::regex express(pattern);
std::smatch	base_match;		std::match_results<std::string::const_iterator>

if(std::regex_match（text,express))
if(std::regex_match (text,std::smatch,express)) 



*/

/*
正则表达式

正则表达式不是C++语言的一部分，主要三种需求：
1.检查一个串是否某种形式的子串；
2. 将匹配的子串替换；
3. 从串中提取出来符合条件的子串

字符分为以下三种字符：
1，普通字符


2. 特殊字符
$ 匹配输入字符串的结尾位置
(,)	标记一个子表达式的开始和结束位置，子表达式可以获取供以后使用
* 匹配前面的子表达式0次或多次
+ 匹配前面的子表达式1次或多次
. 匹配除了换行符\n外的任何单字符
[ 标记一个中括号表达式的开始
？匹配前面的子表达式0次或1次，或指明一个非贪婪限定符
\ 将下一个字符标记为特殊字符、或原义字符、或向后引用、或八进制转义符
^ 匹配输入字符串的开始位置，在方括号表达式中使用，表示不接受该字符集合
{ 标记限定符表达式的开始
| 指明两项之间的一个选择 x|y


3. 限定字符
* 匹配前面的子表达式0次或多次
+ 匹配前面的子表达式1次或多次
？匹配前面的子表达式0次或1次，或指明一个非贪婪限定符
{n} 匹配确定的n次
{n,} 匹配至少n次
{n,m} 匹配至少n次，至多m次

4. 转义
\b 匹配单词边界
\B 匹配非单次边界
\d 数字 [0-9]
\D 非数字 [^0-9]
\w 匹配包括下划线的任何单次字符 [A-Za-Z0-9_]
\W

\t 制表符
\v 垂直制表符
\n 换行符
\f 换页符
\r 回车符



5. 案例
[xyz] 字符集合。匹配所包含的任意一个字符
[^xyz] 负值字符集合，匹配未包含的任意字符
[a-z] 字符范围，匹配指定范围内的任意字符


EXE|DLL|SYS

*/






bool isPe(const std::wstring targetFile)
{
	std::wstring pattern = L"^.*\.(dll)|(exe)|(sys)|(EXE)|(DLL)|(SYS)&";

	std::wregex express(pattern);
	std::wsmatch smatch;
	if (std::regex_match(targetFile, smatch, express))
	{
		for (auto it : smatch)
		{
			std::wcout << it << std::endl;
		}
		return true;
	}

	return false;
}