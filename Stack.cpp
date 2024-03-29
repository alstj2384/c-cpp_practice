/**************************************************
 다음 코드와 실행결과를 참고하여 전역 함수 append()를 작성하고
 전체 프로그램을 완성하시오.
 append()는 Buffer 객체에 문자열을 추가하고
 Buffer 객체에 대한 참조를 반환하는 함수이다.
 **************************************************/

#include <iostream>
#include <string>

using namespace std;

// 클래스 수정 불가
class Buffer {
   string text;
public:
   Buffer(string text) { this->text = text; }  //  생성자

   void add(string next)  {                    // text에 next 문자열 덧붙이기
      text += next;
   }
   void print() {                              // 정보 출력
      cout << text << endl;
   }

   void replace(string s, string r){            // text 의 문자열 변환
       int findex = text.find(s);
       text.replace(findex, s.length(), r);
   }
};


// 여기에  append() 함수 추가
Buffer& append(Buffer& b, string s){
   b.add(s);
   return b;
}



// main 수정 불가
int main() {
   Buffer buf("Hello ");            // 객체 생성

   string str;
   cout << "Enter string : ";       // buf 객체 뒤에 붙일 문자열 입력
   cin >> str;
   Buffer& temp = append(buf, str); // buf의 문자열에  입력된 str 변수의 문자열을 덧붙임

   temp.print();                    // 정보 출력
   buf.print();

   buf.replace("Hello", "Good-Bye");   // "Hello", "Good-Bye"로 변경
   temp.print();
   buf.print();                        // 정보 출력

}

/*
프로그램 실행 결실행결과

(출력)Enter string : (입력)Deok
(출력)Hello Deok
(출력)Hello Deok
(출력)Good-Bye Deok
(출력)Good-Bye Deok
*/