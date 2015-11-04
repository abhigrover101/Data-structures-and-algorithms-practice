#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<map>

using namespace std;

struct node{
    string value;
    node *left;
    node *right;
};




bool isOperand(char ch){
    if(ch>='a' && ch<='z')
        return true;
    if(ch>='A' && ch<='Z')
        return true;

    return false;
}

bool isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return true;
    return false;
}

int main(){
    map< char,int > precedence;
    precedence.insert(pair<char,int > ('/',3));
    precedence.insert(pair<char,int>('*',2));
    precedence.insert(pair<char,int>('-',1));
    precedence.insert(pair<char,int>('+',1));

    string input="",output="";
    char temp='\0';
    cin>>input;
    int i;
    stack<char> tokens;
    for(i=0;i<input.size();i++){
        if(isOperand(input[i])){
            output=output+input[i];
        }
        else{
            if(input[i]==')'){
                if(!tokens.empty()){
                    temp = tokens.top();
                    tokens.pop();
                }
                while(temp!='(' && temp!='\0'){
                    output+=temp;
                    if(tokens.empty())
                        break;
                    temp = tokens.top();
                    tokens.pop();
                }
            }
            else if(isOperator(input[i])){
                if(!tokens.empty()){
                    temp = tokens.top();
                    tokens.pop();
                }
                while(precedence[temp]>=precedence[input[i]] && temp!='(' && temp!='\0'){
                    output+=temp;
                    if(tokens.empty())
                        break;
                    temp = tokens.top();
                    tokens.pop();
                }
                if(isOperator(temp) || temp=='('){
                    tokens.push(temp);
                }
                tokens.push(input[i]);
            }
            else if(input[i]=='('){
               // if(!tokens.empty())
                //    cout<<tokens.top()<<endl;
                tokens.push(input[i]);
                //cout<<"yes\n";
                }
        }
        temp='\0';
    }
    cout<<output<<endl;
    while(!tokens.empty()){
        output+=tokens.top();
        tokens.pop();
    }
    cout<<output<<endl;
    return 0;
}
