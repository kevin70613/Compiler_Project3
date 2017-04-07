#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<cctype>

using namespace std;

fstream fileIn;  // read grammar.txt
fstream fileIn2; // read main.c
fstream fileIn3; // read main.c
fstream fileOut; // write symbol_table.txt
fstream fileOut2;   // write main.ll
fstream fileOut3;  // tree


//Node structure : this node structure => linked list -- stack
class Node {
   private:
      string data;
      int num;
   public:
      Node(string data,int num);
      string getData();
      int getNum();
      void setData(string inputData);
      void setNum(int intNum);
};

Node::Node(string data,int num){
   setData(data);
   setNum(num);
}

void Node::setData(string data){
   this->data = data;
}

void Node::setNum(int num){
   this->num = num;
}

string Node::getData(){
   return this->data;
}

int Node::getNum(){
   return this->num;
}

class Node3 {
   private:
      string id;
      string type;
      int array;
      int num;
   public:
      Node3(int num,string type,int array,string id);
      string getType();
      int getNum();
      int getArray();
      string getId();
      void setType(string inputData);
      void setNum(int intNum);
      void setArray(int inputArray);
      void setId(string inputId);
};

Node3::Node3(int num,string type,int array,string id){
   setType(type);
   setNum(num);
   setArray(array);
   setId(id);
}

void Node3::setId(string id){
   this->id = id;
}

void Node3::setType(string type){
   this->type = type;
}

void Node3::setNum(int num){
   this->num = num;
}

void Node3::setArray(int array){
   this->array = array;
}

string Node3::getId(){
   return this->id;
}

string Node3::getType(){
   return this->type;
}

int Node3::getNum(){
   return this->num;
}

int Node3::getArray(){
   return this->array;
}

//Node2 structure : this node structure for vector
class Node2 {
   private:
      string symbol;
      string type;
      int scope;
      int array;
      int function;
      string size; // for array size
      int param;
   public:
      Node2(int scope,string symbol,string type,int array,int function,string size);
      string getSymbol();
      string getType();
      string getArraySize();
      int getScope();
      int getArray();
      int getFunction();
      int getParam();
      void setSymbol(string inputSymbol);
      void setType(string inputType);
      void setScope(int inputScope);
      void setArray(int inputArray);
      void setFunction(int inputfun);
      void setArraySize(string size);
      void setParam(int num);
};
  
Node2::Node2(int scope,string symbol,string type,int array,int function,string size){
   setSymbol(symbol);
   setType(type);
   setScope(scope);
   setArray(array);
   setFunction(function);
   setArraySize(size);
   setParam(0);
}
 
void Node2::setParam(int num){
   this->param = num;
}

void Node2::setSymbol(string symbol){
   this->symbol = symbol;
}
  
void Node2::setType(string type){
   this->type = type;
}
  
void Node2::setScope(int scope){
   this->scope = scope;
}
 
void Node2::setArray(int array){
   this->array = array;
}
 
void Node2::setFunction(int function){
   this->function = function;
}

void Node2::setArraySize(string size){
   this->size = size;
}
 
int Node2::getParam(){
   return this->param;
}
 
string Node2::getSymbol(){
   return this->symbol;
}
 
string Node2::getType(){
   return this->type;
}
  
int Node2::getScope(){
   return this->scope;
}
 
int Node2::getArray(){
   return this->array;
}
 
int Node2::getFunction(){
   return this->function;
}

string Node2::getArraySize(){
   return this->size;
}

//TreeNode class : store the tree information
class TreeNode {
   private:
      int treeLevel; 
      string treeNode;
   public:
      TreeNode(int level, string node);
      void setTreeLevel(int level);
      void setTreeNode(string node);
      int getTreeLevel();
      string getTreeNode();
};

TreeNode::TreeNode(int level, string node){
    setTreeLevel(level);
    setTreeNode(node);
}

void TreeNode::setTreeLevel(int level){
    this->treeLevel = level;
}

void TreeNode::setTreeNode(string node){
    this->treeNode = node;
}

int TreeNode::getTreeLevel(){
   return this->treeLevel;
}

string TreeNode::getTreeNode(){
   return this->treeNode;
}

vector<string> mainC;      // store main.c
vector<Node2> symbolTable; // store symbolTable
vector<TreeNode> tree;     // store abstract syntax tree
int scope = 0;             // store the scope
int tempRegNum = 1;        // temp register number start from 1
int funcParamNum = 0;
vector<string> mainLine[500];
vector<Node3> funcParam;

// lexical analyzer
void numDFA(string inputstr);
void idDFA(string inputstr);
string numDFASym(string inputstr);
string itos(int x);

//Code generation function
void S(int index,int treeLevel);
void Program(int index,int treeLevel);
void DeclList(int index,int treeLevel);
void DeclList1(int index,int treeLevel);
string Decl(int index,int treeLevel);
void VarDecl(int index,int treeLevel);
string VarDecl1(int index,int treeLevel);
string FunDecl(int index,int treeLevel);
void VarDeclList(int index,int treeLevel);
void ParamDeclList(int index,int treeLevel);
void ParamDeclListTail(int index,int treeLevel);
void ParamDeclListTail1(int index,int treeLevel);
void ParamDecl(int index,int treeLevel);
string ParamDecl1(int index,int treeLevel);
void Block(int index,int treeLevel);
string Type(int index,int treeLevel);
void StmtList(int index,int treeLevel);
void StmtList1(int index,int treeLevel);
void Stmt(int index,int treeLevel);
string Expr1(int index,int treeLevel);
string UnaryOp(int index,int treeLevel);
string BinOp(int index,int treeLevel);
string Num(int index,int treeLevel);
string Id(int index,int treeLevel);
string Expr(int index,int treeLevel);
string ExprIdTail(int index,int treeLevel,string id);
string ExprArrayTail(int index,int treeLevel);
string ExprList(int index,int treeLevel);
string ExprListTail(int index,int treeLevel);
string ExprListTail1(int index,int treeLevel);


int main(){
   // line for input string
  string line;
   // use lhsCOunt to record the number of left hand side( nonterminal )
  int lhsCount = 0; 
  vector<string> nonTerminals;
  vector<string> rhs;
  vector<string> terminals;
   // use array of vectors to store lhs corresponding rhs
  vector<string> derRule[500]; // still has problem => change to unknown size
 
  fileIn.open("grammar.txt",ios::in);
  fileIn2.open("main.c",ios::in);
  fileIn3.open("main.c",ios::in);
  fileOut.open("symbol_table.txt",ios::out);
  fileOut2.open("main.ll",ios::out);

  //=====  preprocessing ======
  while( getline(fileIn,line) ){
     string tab = "	";
     if(line[0] != tab[0] && line.size() != 0){  //check line is not start with white space and not null
        nonTerminals.push_back(line);
        lhsCount++;
     }
     else{  // right hand size
        if(line.size() != 0){ //check line is not null
           string rhsString = line.substr(line.find_first_not_of("	"),line.size()-line.find_first_not_of(" "));
           derRule[lhsCount-1].push_back(rhsString); // push rhs to corresponding lhs 
           rhs.push_back(rhsString);
        }
    }
  }
  fileIn.close();
   // find the terminals
  for(int i=0;i<rhs.size();i++){
     int head = 0, tail = 0; // head -> noncheck string head ; tail -> noncheck string tail
     while( (head + tail) < rhs[i].size() ){  // head + tail is the length of checked string
        if( rhs[i].substr(head+tail,1).compare(" ") != 0 ){
           tail++;
        }else{  // case find the candidate
           int flag = 1; // use to check substr is not nonterminals
           string candiTer = rhs[i].substr(head,tail);
           for(int j=0;j<nonTerminals.size();j++){
               if(candiTer.compare(nonTerminals[j]) == 0)
                  flag *= 0;
               else 
                  flag *= 1;
           }
           if(flag == 1){ //flag is 1 => terminals ,0 => nonterminals
               int testRepit = 1;
               if(terminals.size() == 0 )  //Terminals doesn't have anything
                  terminals.push_back(candiTer);
               else{   // Terminals have something, must check repi terminal not to store it again
                  for(int k=0;k<terminals.size();k++){
                     if(candiTer.compare(terminals[k]) == 0 )
                         testRepit *= 0; // already store this terminals to Terminals
                     else
                         testRepit *= 1;
                  }
                  if(testRepit == 1)
                     terminals.push_back(candiTer);
               }    
           }
             // update the head and tail
           head = head + tail + 1;  // update the head to new uncheck string 
           tail = 0;
        }
         // case meet the end of rhs string ( length = head + tail )
        if( (head + tail) == rhs[i].size()) {
           int flag = 1; // use to check substr is not nonterminals
           string candiTer = rhs[i].substr(head,tail);
           for(int j=0;j<nonTerminals.size();j++){
               if(candiTer.compare(nonTerminals[j]) == 0)
                  flag *= 0;
               else
                  flag *= 1;
           }
           if(flag == 1){ //flag is 1 => terminals ,0 => nonterminals
               int testRepit = 1;
               if(terminals.size() == 0 )  //Terminals doesn't have anything
                  terminals.push_back(candiTer);
               else{   // Terminals have something, must check repi terminal not to store it again
                  for(int k=0;k<terminals.size();k++){
                     if(candiTer.compare(terminals[k]) == 0 )
                         testRepit *= 0; // already store this terminals to Terminals
                     else
                         testRepit *= 1;
                  }
                  if(testRepit == 1)
                     terminals.push_back(candiTer);
               }
           }
             // update the head and tail
           head = head + tail + 1;  // update the head to new uncheck string 
           tail = 0;
        }
     }
  }

  // ==  find the first set ==
  vector<string> nullableSet;  // this vector store the nullable set of nonterminals 
  // this array of vectors use to store the first set of terminals and nonterminals
  vector<string> firstSet[nonTerminals.size()+terminals.size()];
  // this array of vectors yse to store the process which nonTerminals to find terminals first set
  vector<string> LLTableNontoTer[nonTerminals.size()];

  // find the nullable set
  for(int i=0;i<nonTerminals.size();i++){
     for(int j=0;j<derRule[i].size();j++){
          // find every nonterminals rhs has epsilon or not
         if(derRule[i][j].compare("epsilon") == 0)
             nullableSet.push_back(nonTerminals[i]);
     }
  }
  
  for(int i=0;i<nonTerminals.size();i++){
     for(int j=0;j<derRule[i].size();j++){
          // find every nonterminals rhs has epsilon or not
         for(int k=0;k<nullableSet.size();k++){
             if(derRule[i][j].compare(nullableSet[k]) == 0){
                 int noRepi = 1;
                 for(int l=0;l<nullableSet.size();l++){
                     if(nonTerminals[i].compare(nullableSet[l])==0)
                        noRepi *= 0;
                 }
                 if(noRepi == 1)
                     nullableSet.push_back(nonTerminals[i]);
             }
         }
     }
  }

  // first part is for terminals
  for(int i=0;i<terminals.size();i++)
     firstSet[i].push_back(terminals[i]);

  // second part is for nonterminals
  // first time to find first set
  int nonTerIndex = terminals.size();  // get the start index of nonterminals

  for(int i=0;i<nonTerminals.size();i++){
      for(int j=0;j<derRule[i].size();j++){
         int head = 0, tail = 0;
         int findFirst = 1; // this variable use to find the first token of string
         while(findFirst){
            if( derRule[i][j].substr(head+tail,1).compare(" ") != 0 ){
                tail++;
            }else{  // case find the candidate
                int nullFlag = 1;  // this flag test the nullable or not
                string candiTer = derRule[i][j].substr(head,tail);
                 //test this candidate is nullable or not
                for(int k=0;k<nullableSet.size();k++){
                     if(candiTer.compare(nullableSet[k]) == 0)
                          nullFlag *= 0;
                     else 
                          nullFlag *= 1;
                }
                if(nullFlag == 0){ // this is nullable
                      // update new head and tail and continuous to run while loop
                     firstSet[nonTerIndex].push_back(candiTer);  //
                     LLTableNontoTer[i].push_back(candiTer);     //
                     head = head + tail + 1;
                     tail = 0;               
                }else{ // not nullalbe
                     firstSet[nonTerIndex].push_back(candiTer);
                     LLTableNontoTer[i].push_back(candiTer);
                     findFirst = 0; // break while loop
                }
            }
             // case meet the end of rhs string ( length = head + tail )
            if( (head + tail) == derRule[i][j].size()) {
                string candiTer = derRule[i][j].substr(head,tail);
                firstSet[nonTerIndex].push_back(candiTer);
                LLTableNontoTer[i].push_back(candiTer);
                findFirst = 0;
            }
         }
      }
      nonTerIndex++; // go to next index to store the next nonterminals first set
  }
   // change the result which has nonterminals found first iteration to all terminals
  int allTer = 1; // this flag check all firstSet is terminals
  int jCount = 0;
  while(allTer){
    int allTerCount = 0; // this variable count the number of terminals
     for(int i=0;i<nonTerminals.size();i++){
        int hasNonTer = 1;
        jCount = 0;
        for(int j=0;j<firstSet[terminals.size()+i].size();j++){
             // test has nonTerminals or not
            for(int k=0;k<nonTerminals.size();k++){
               if(firstSet[terminals.size()+i][j].compare(nonTerminals[k]) == 0){ // get the nonTerminals
                   for(int l=0;l<firstSet[terminals.size()+k].size();l++){
                       // push this nonTerminals first set to the firstSet
                      LLTableNontoTer[i].push_back(firstSet[terminals.size()+k][l]+" "+LLTableNontoTer[i][j+jCount]);
                      int notReplica = 1;
                      for(int m=0;m<firstSet[i].size();m++){ // test  avoid replica
                          if(firstSet[terminals.size()+k][l].compare(firstSet[terminals.size()+i][m])==0)
                             notReplica *= 0;
                          else notReplica *= 1;
                      }
                      if(notReplica == 1)
                         firstSet[terminals.size()+i].push_back(firstSet[ terminals.size()+k ][l]); 
                   }
                   firstSet[terminals.size()+i].erase(firstSet[terminals.size()+i].begin()+j); // delete the jth element
                   j = j-1; // because delete one element the next element will move forward => change pointer  
                   hasNonTer *= 0;
                   jCount++;
                   k=nonTerminals.size(); // break this find nonTerminals loop
               }
            }
        }
        if(hasNonTer == 1){ // this element of first set is all terminals
           allTerCount++;
        }
     }
     if(allTerCount == nonTerminals.size() )   // all nonTerminals first set are terminals
        allTer = 0;
  }
  
  // == find the follow set  ==
  vector<string> rhsToken[rhs.size()];  // store each token of rhs
  vector<string> followSet[terminals.size()+nonTerminals.size()];    // store the follow set
  // find right hand side token
  for(int i=0;i<rhs.size();i++){
      // find the terminals
     int head = 0, tail = 0; // head -> noncheck string head ; tail -> noncheck string tail
     while( (head + tail) < rhs[i].size() ){  // head + tail is the length of checked string
        if( rhs[i].substr(head+tail,1).compare(" ") != 0 ){
           tail++;
        }else{  // case find the candidate
           string candi = rhs[i].substr(head,tail);
           rhsToken[i].push_back(candi);
              // update the head and tail
           head = head + tail + 1;  // update the head to new uncheck string 
           tail = 0;
        }
         // case meet the end of rhs string ( length = head + tail )
        if( (head + tail) == rhs[i].size()) {
           string candi = rhs[i].substr(head,tail);
           rhsToken[i].push_back(candi);
             // update the head and tail
           head = head + tail + 1;  // update the head to new uncheck string 
           tail = 0;
        }
     }
  }
  // find the case 1: start symbol contains $
  followSet[terminals.size()].push_back("$");
 
  // find the case 2: A->aXB  first(B)-{epsilon} = follow(X)
  // nonTerminals case
  for(int i=0;i<nonTerminals.size();i++){
     for(int j=0;j<rhs.size();j++){
         for(int k=0;k<rhsToken[j].size();k++){
               //find each nonterminals in this case follow set
              if(rhsToken[j][k].compare(nonTerminals[i])==0){  
                  // check is not the last and can use case 2 
                  if(k < rhsToken[j].size()-1){ // not the right most 
                       //get the first set
                       //handle the terminals case first set doesn't contain epsilon without epsilon
                      for(int m=0;m<terminals.size();m++){ 
                          if(rhsToken[j][k+1].compare(terminals[m])==0 /*&& rhsToken[j][k+1].compare("epsilon")!=0*/){ 
                           // find the next token which is terminals 
                              for(int n=0;n<firstSet[m].size();n++){  // check this terminals token first set
                                   //test not repeat one 
                                  int repiFlag = 1; //this variable test the repeat
                                  for(int p=0;p<followSet[terminals.size()+i].size();p++){
                                      if(firstSet[m][n].compare(followSet[terminals.size()+i][p])==0)
                                           repiFlag *= 0;
                                  } 
                                   // doesn't find before and add to follow set
                                  if(repiFlag == 1 && firstSet[m][n].compare("epsilon") != 0)  
                                     followSet[terminals.size()+i].push_back(firstSet[m][n]);
                              }
                          }
                      }    
                       //handle the nonTerminals case
                      for(int m=0;m<nonTerminals.size();m++){
                          if(rhsToken[j][k+1].compare(nonTerminals[m])==0){ // next token is nonterminals      
                              for(int n=0;n<firstSet[terminals.size()+m].size();n++){
                                   int repiFlag = 1; //this variable test the repeat
                                   for(int p=0;p<followSet[terminals.size()+i].size();p++){
                                       if(firstSet[terminals.size()+m][n].compare(followSet[terminals.size()+i][p])==0)
                                           repiFlag *= 0;
                                   }
                                   // doesn't find before and add to follow set
                                   if(repiFlag == 1 && firstSet[terminals.size()+m][n].compare("epsilon") != 0)
                                      followSet[terminals.size()+i].push_back(firstSet[terminals.size()+m][n]);
                              }
                          }
                      }
                  
                  }
              }
         }
     }
  }
   
  int lastTimeCount = 0;
  int rhsCount = 0;
  
  int count =0;
  while(count <3){
  lastTimeCount = 0;
  rhsCount = 0;
  for(int i=0;i<nonTerminals.size();i++){
      rhsCount += derRule[i].size(); // count every lhs's rhs
      for(int j=lastTimeCount;j<rhsCount;j++){
         int rightMost = rhsToken[j].size()-1;
         // right most is not epsilon
         int hasEpsilon = 1;
         while(hasEpsilon){
            int epsiFlag = 1; // check has epsilon in first set
            if(rightMost>=0 && rhsToken[j][rightMost].compare("epsilon")!=0){
                // right most token is nonTerminals
                int nonTerFG = 1;
                for(int k=0;k<nonTerminals.size();k++){
                    
                    if(rhsToken[j][rightMost].compare(nonTerminals[k])==0){
                        nonTerFG *= 0;
                        // find is order of this nonTerminals
                        int nonIndex = 0; //nonIndex is for nonTerminals
                        for(int m=0;m<nonTerminals.size();m++)
                            if(nonTerminals[k].compare(nonTerminals[m])==0)
                                nonIndex = m;  // asign index of the nonterminals to nonIndex
                        for(int l=0;l<firstSet[terminals.size()+nonIndex].size();l++){
                             if(firstSet[terminals.size()+nonIndex][l].compare("epsilon")==0){
                                epsiFlag *= 0;
                             }
                        }
                        // this case is A->abX , follow(A) = follow(X)
                        for(int l=0;l<followSet[terminals.size()+i].size();l++){
                           //test not repeat one
                           int repiFlag = 1; //this variable test the repeat
                           for(int p=0;p<followSet[terminals.size()+nonIndex].size();p++){
                               if(followSet[terminals.size()+i][l].compare(followSet[terminals.size()+nonIndex][p])==0)
                                   repiFlag *= 0;
                           }
                            // doesn't find before and add to follow set
                           if(repiFlag == 1 && followSet[terminals.size()+i][l].compare("epsilon") != 0){
                                followSet[terminals.size()+nonIndex].push_back(followSet[terminals.size()+i][l]);
                           }
                        }
                        if(epsiFlag == 0){  // right most token first set contain epsilon
                           rightMost--;
                        }
                        if(epsiFlag == 1 || rightMost < 0){  // not epsilon or out of size
                           hasEpsilon = 0;
                           k = nonTerminals.size(); // break the for loop
                        }
                    }
                }
                if(nonTerFG == 1){ // right most token is terminals
                    hasEpsilon = 0;
                }
            }
            if(rightMost==0 && rhsToken[j][rightMost].compare("epsilon")==0)
                hasEpsilon = 0;
            //cout << "hasEpsilon =" << hasEpsilon << endl;
        }
        lastTimeCount = rhsCount; // update last time of count
     }
  }
  count++;
  }
   
  //===== Construct LLTable   =========
  vector<string> LLtableTer;    // store LLtable terminals
  vector<string> LLtableNon;    // store LLtable nonterminals
  vector<string> LLtableRule;   // store LLtable derivation rule

  for(int i=0;i<nonTerminals.size();i++){
      // rule 1 to construct LLtable
     for(int j=0;j<LLTableNontoTer[i].size();j++){
         // find the terminals
        int head = 0, tail = 0; // head -> noncheck string head ; tail -> noncheck string tail
        string candiTer = "";
        string candiNon = "";
         // find the first one(terminals)
        int findFir = 1; 
        while( findFir ){  // head + tail is the length of checked string
            if( LLTableNontoTer[i][j].substr(head+tail,1).compare(" ") != 0 ){
                tail++;
            }else{  // case find the candidate
                candiTer = LLTableNontoTer[i][j].substr(head,tail);
                findFir = 0;
            }
             // case meet the end of rhs string ( length = head + tail )
            if( (head + tail) == LLTableNontoTer[i][j].size()) {
                candiTer = LLTableNontoTer[i][j].substr(head,tail);
                findFir = 0;
            }
        }
         // find the last one(original nonterminals) 
        head = 0;
        tail = 0;
        while( (head + tail) < LLTableNontoTer[i][j].size() ){  // head + tail is the length of checked string
            if( LLTableNontoTer[i][j].substr(head+tail,1).compare(" ") != 0 ){
                tail++;
            }else{  
                candiNon = LLTableNontoTer[i][j].substr(head,tail);
                 // update the head and tail
                head = head + tail + 1;  // update the head to new uncheck string 
                tail = 0;
            }
             // case meet the end of rhs string ( length = head + tail )
            if( (head + tail) == LLTableNontoTer[i][j].size()) {
                candiNon = LLTableNontoTer[i][j].substr(head,tail);
                 // update the head and tail
                head = head + tail + 1;  // update the head to new uncheck string 
                tail = 0;
            }
        }
        for(int k=0;k<terminals.size();k++){
            if(candiTer.compare(terminals[k])==0){
                for(int n=0;n<derRule[i].size();n++){
                     // find the terminals
                    int head = 0, tail = 0; // head -> noncheck string head ; tail -> noncheck string tail
                    string candiTest = "";  // use to get the first of rhs 
                    while((head+tail) < derRule[i][n].size() ){  // head + tail is the length of checked string
                        if( derRule[i][n].substr(head+tail,1).compare(" ") != 0 ){
                            tail++;
                        }else{  // case find the candidate
                            candiTest = derRule[i][n].substr(head,tail);
                            head = derRule[i][n].size(); // break while condition
                        }
                         // case meet the end of rhs string ( length = head + tail )
                        if( (head + tail) == derRule[i][n].size()) {
                            candiTest = derRule[i][n].substr(head,tail);
                            head = derRule[i][n].size(); 
                        }
                    }
                    //test the candiTest equals candiNon or not
                    if(candiNon.compare(candiTest)==0){
                        LLtableNon.push_back(nonTerminals[i]);
                        LLtableTer.push_back(candiTer);
                        LLtableRule.push_back(derRule[i][n]); 
                    }

                }
            }
        }
      
     }
      // rule 2 and 3 to construct LLtable
     for(int n=0;n<derRule[i].size();n++){
        // test follow set has $ or not
        int head = 0, tail = 0; // head -> noncheck string head ; tail -> noncheck string tail
        string candiTest = "";  // use to get the first of rhs 
        while((head+tail) < derRule[i][n].size() ){  // head + tail is the length of checked string
            if( derRule[i][n].substr(head+tail,1).compare(" ") != 0 ){
                tail++;
            }else{  // case find the candidate
                candiTest = derRule[i][n].substr(head,tail);
                head = derRule[i][n].size(); // break while condition
            }
            // case meet the end of rhs string ( length = head + tail )
            if( (head + tail) == derRule[i][n].size()) {
                candiTest = derRule[i][n].substr(head,tail);
                head = derRule[i][n].size();
            }
        }
        for(int t=0;t<nonTerminals.size();t++){
            if(candiTest.compare(nonTerminals[t])==0){  // find what nonterminals the candiTest is 
                for(int v=0;v<firstSet[terminals.size()+t].size();v++){
                    if(firstSet[terminals.size()+t][v].compare("epsilon")==0){   // test first set has epsilon 
                        // rule 2
                       for(int u=0;u<followSet[terminals.size()+i].size();u++){
                           if(followSet[terminals.size()+i][u].compare("$")==0){
                               LLtableNon.push_back(nonTerminals[i]);
                               LLtableTer.push_back("$");
                               LLtableRule.push_back(derRule[i][n]);
                           }
                       }
                        // rule 3
                       for(int w=0;w<followSet[terminals.size()+i].size();w++){
                           LLtableNon.push_back(nonTerminals[i]);
                           LLtableTer.push_back(followSet[terminals.size()+i][w]);
                           LLtableRule.push_back(derRule[i][n]);
                       }
                    }
                }
            }
             //test caniTest is epsilon or not  => rule 3
            if(candiTest.compare("epsilon")==0){ // first of epsilon is epsilon
                for(int w=0;w<followSet[terminals.size()+i].size();w++){
                    LLtableNon.push_back(nonTerminals[i]);
                    LLtableTer.push_back(followSet[terminals.size()+i][w]);
                    LLtableRule.push_back(derRule[i][n]);
                }
            }
               
        }
     }
     
  }
  // ============ produce derivation tree  ========
  // ===  hw1 : lexical analyzer
  while( getline(fileIn2,line) ){
      // store the current front of string which doesn't check
     int front = 0;
      // check substring length
     int length = 1;
     int state = 0;
     for(length=1;length<line.size()-front+1;length++ ){
          string subLine = line.substr(front,length);
          if(subLine.size() >= 6 && !state){
               // check the keyword
             if( (subLine.substr(subLine.size()-6,6).compare("double") == 0 ||
                  subLine.substr(subLine.size()-6,6).compare("return") == 0 ||
                  subLine.substr(subLine.size()-6,6).compare("return") == 0) && subLine.size() == 6 ){
                 string nextStr = line.substr(front,length+1);
                   // check the next char is white space or not
                   // use isspace to check whitespace,note: this function needs char not string!
                 if( isspace(nextStr[nextStr.size()-1]) || nextStr.substr(nextStr.size()-1,1).compare("\n")==0 ){
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-6));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-6));
         
                     mainC.push_back(subLine.substr(subLine.size()-6,6));
                     state = 1;
                 }
             }
             else if( (subLine.substr(subLine.size()-6,6).compare("double") == 0 ||
                       subLine.substr(subLine.size()-6,6).compare("return") == 0
                       ) && subLine.size() > 6 ){
                       // identifier which contain those keywords
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-6));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-6));
                    
                     state = 1;
             }
          }
            // check the last five words
          if(subLine.size() >= 5 && !state){
                // check the keywords
             if( (subLine.substr(subLine.size()-5,5).compare("float")==0 || subLine.substr(subLine.size()-5,5).compare("while")==0 ||
                  subLine.substr(subLine.size()-5,5).compare("break")==0 || subLine.substr(subLine.size()-5,5).compare("print")==0)
                  && subLine.size()==5 ){
  
                 string nextStr2 = line.substr(front,length+1);
                   // check the next char is white space or not
                   // use isspace to check whitespace,note: this function needs char not string!
                 if( isspace(nextStr2[nextStr2.size()-1]) || nextStr2.substr(nextStr2.size()-1,1).compare("\n")==0 ){
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-5));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-5));
   
                     mainC.push_back(subLine.substr(subLine.size()-5,5));
                     state = 1;
                 }
             }
             else if( (subLine.substr(subLine.size()-5,5).compare("float")==0 ||
                       subLine.substr(subLine.size()-5,5).compare("while")==0 ||
                       subLine.substr(subLine.size()-5,5).compare("break")==0 ||
                       subLine.substr(subLine.size()-5,5).compare("print")==0 ) && subLine.size()>5 ){
                       // identifier which contain those keywords
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-5));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-5));
   
                     state = 1;
              }
          }
            // check the last four words
          if(subLine.size() >= 4 && !state){
               // check the keywords
             if( (subLine.substr(subLine.size()-4,4).compare("char")==0 || subLine.substr(subLine.size()-4,4).compare("else")==0)
                   && subLine.size() == 4 ){
  
                 string nextStr3 = line.substr(front,length+1);
                   // check the next char is white space or not
                   // use isspace to check whitespace,note: this function needs char not string!
                 if( isspace(nextStr3[nextStr3.size()-1]) || nextStr3.substr(nextStr3.size()-1,1).compare("\n")==0  ){
                        // check is number or not
                      numDFA(subLine.substr(0,subLine.size()-4));
                        // check is identifier or not
                      idDFA(subLine.substr(0,subLine.size()-4));
   
                      mainC.push_back(/*"Keyword "+*/subLine.substr(subLine.size()-4,4));
                      state = 1;
                 }
             }else if((subLine.substr(subLine.size()-4,4).compare("char")==0 || subLine.substr(subLine.size()-4,4).compare("else")==0)
                        && subLine.size() > 4 ){ // identifier which contain those keywords
                     // check is number or not
                   numDFA(subLine.substr(0,subLine.size()-4));
                     // check is identifier or not
                   idDFA(subLine.substr(0,subLine.size()-4));
   
                   state = 1;
             }
          }
            // check the last three words
          if(subLine.size() >= 3 && !state){
               // check the keywords
             if( (subLine.substr(subLine.size()-3,3).compare("int")==0 || subLine.substr(subLine.size()-3,3).compare("for")==0)
                  && subLine.size()==3 ){
  
                 string nextStr4 = line.substr(front,length+1);
                   // check the next char is white space or not
                   // use isspace to check whitespace,note: this function needs char not string!
                 if( isspace(nextStr4[nextStr4.size()-1]) || nextStr4.substr(nextStr4.size()-1,1).compare("\n")==0 ){
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-3));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-3));
   
                     mainC.push_back(subLine.substr(subLine.size()-3,3));
                     state = 1;
                 }
             }else if( (subLine.substr(subLine.size()-3,3).compare("int")==0 || subLine.substr(subLine.size()-3,3).compare("for")==0)
                        && subLine.size() > 3){// identifier which contain those keywords
                      // check is number or not
                    numDFA(subLine.substr(0,subLine.size()-3));
                      // check is identifier or not
                    idDFA(subLine.substr(0,subLine.size()-3));
   
                    state = 1;
             }
          }
           // check the last two words
          if(subLine.size() >= 2 && !state){
               // check the keywords
             if( (subLine.substr(subLine.size()-2,2).compare("if") == 0) && subLine.size() == 2){
  
                 string nextStr5 = line.substr(front,length+1);
                   // check the next char is white space or not
                   // use isspace to check whitespace,note: this function needs char not string!
                 if( isspace(nextStr5[nextStr5.size()-1]) || nextStr5.substr(nextStr5.size()-1,1).compare("\n")==0 ){
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-2));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-2));
   
                     mainC.push_back(subLine.substr(subLine.size()-2,2));
                     state = 1;
                 }
             }else if( (subLine.substr(subLine.size()-2,2).compare("if") == 0) && subLine.size() > 2){
                       // identifier which contain those keywords
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-2));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-2));
   
                     state = 1;
            }
              // check the Operators
            if(subLine.substr(subLine.size()-2,2).compare("==") == 0 || subLine.substr(subLine.size()-2,2).compare("!=") == 0 ||
               subLine.substr(subLine.size()-2,2).compare(">=") == 0 || subLine.substr(subLine.size()-2,2).compare("<=") == 0 ||
               subLine.substr(subLine.size()-2,2).compare("&&") == 0 || subLine.substr(subLine.size()-2,2).compare("||") == 0 ){
                   // check is number or not
                 numDFA(subLine.substr(0,subLine.size()-2));
                   // check is identifier or not
                 idDFA(subLine.substr(0,subLine.size()-2));
   
                 mainC.push_back(subLine.substr(subLine.size()-2,2));
                 state = 1;
             }                 
              // check comment, ignore the comment
             else if(subLine.substr(subLine.size()-2,2).compare("//")==0){
                   // check is number or not
                 numDFA(subLine.substr(0,subLine.size()-2));
                   // check is identifier or not
                 idDFA(subLine.substr(0,subLine.size()-2));
                 length = line.size()-front+1;
                 state = 1;
             }
          }
            // check the last one word       
          if(subLine.size() >= 1 && !state){
              // check the whitespace
              // use isspace to check whitespace,note: this function needs char not string!
             if( isspace(subLine[subLine.size()-1])){
                   // check is number or not
                 numDFA(subLine.substr(0,subLine.size()-1));
                   // check is identifier or not
                 idDFA(subLine.substr(0,subLine.size()-1));
   
                 state = 1;
  
                   // check the case ' '
                 if( line.substr(front,length+1).compare("' '")==0 ){
                    state = 0;
                 }
 
             }
               // check the operators
             else if(subLine.substr(subLine.size()-1,1).compare("=") == 0 || subLine.substr(subLine.size()-1,1).compare("!") == 0 ||
                     subLine.substr(subLine.size()-1,1).compare("+") == 0 || subLine.substr(subLine.size()-1,1).compare("-") == 0 ||
                     subLine.substr(subLine.size()-1,1).compare("*") == 0 || subLine.substr(subLine.size()-1,1).compare("<") == 0 ||
                     subLine.substr(subLine.size()-1,1).compare(">") == 0 ){
                  // check the next char
                 string temp = line.substr(front,length+1);
                 if(!(temp.substr(temp.size()-2,2).compare("==") == 0 || temp.substr(temp.size()-2,2).compare("!=") == 0 ||
                      temp.substr(temp.size()-2,2).compare(">=") == 0 || temp.substr(temp.size()-2,2).compare("<=") == 0 ||
                      temp.substr(temp.size()-2,2).compare("+=") == 0 || temp.substr(temp.size()-2,2).compare("-=") == 0 ||
                      temp.substr(temp.size()-2,2).compare("*=") == 0) ){
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-1));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-1));
   
                     mainC.push_back(subLine.substr(subLine.size()-1,1));
                     state = 1;
                 }
   
             }
                // check the special symbols
             else if(subLine.substr(subLine.size()-1,1).compare("[") == 0 || subLine.substr(subLine.size()-1,1).compare("]") == 0 ||
                     subLine.substr(subLine.size()-1,1).compare("(") == 0 || subLine.substr(subLine.size()-1,1).compare(")") == 0 ||
                     subLine.substr(subLine.size()-1,1).compare("{") == 0 || subLine.substr(subLine.size()-1,1).compare("}") == 0 ||
                     subLine.substr(subLine.size()-1,1).compare(";") == 0 || subLine.substr(subLine.size()-1,1).compare(",") == 0 ){
                   // check is number or not
                 numDFA(subLine.substr(0,subLine.size()-1));
                   // check is identifier or not
                 idDFA(subLine.substr(0,subLine.size()-1));
   
                 mainC.push_back(subLine.substr(subLine.size()-1,1));
                 state = 1;
             }
              // / is the special case, because // and / are ambiguous
             else if(subLine.substr(subLine.size()-1,1).compare("/") == 0){
                 string temp2 = line.substr(front,length+1);
                 if( !(temp2.substr(temp2.size()-2,2).compare("//") == 0)){
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-1));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-1));
   
                     mainC.push_back(subLine.substr(subLine.size()-1,1));
                     state = 1;
                 }
             }
          }
            // check has enter the state or not
          if(state == 1){
             front = front+length;
               // change front to remove subString
             length = 0;
               // length set to 0
             state = 0;
          }
     }
  }
  fileIn2.close();
   //push end symbol $ to mainC stack
  mainC.push_back("$");
  // ===
  vector<Node> stackList;  // this vector use as stack
  stackList.push_back(Node("S",1));
  int stackTop = 0; // point to the top of stack
  int mainTop = 0;
  int treeLevel = stackList[stackTop].getNum();
  while( stackList.size()>0 ){
     for(int i=0;i<LLtableNon.size();i++){
        if(stackList[stackTop].getData().compare(LLtableNon[i])==0){ //get the top of stack
            if(LLtableTer[i].compare(mainC[mainTop]) == 0){  // find the terminals
               vector<string> temp;
               int head = 0, tail = 0; // head -> noncheck string head ; tail -> noncheck string tail
               while( (head + tail) < LLtableRule[i].size() ){  // head + tail is the length of checked string
                   if( LLtableRule[i].substr(head+tail,1).compare(" ") != 0 ){
                      tail++;
                   }else{  // case find the candidate
                      string candi = LLtableRule[i].substr(head,tail);
                      temp.push_back(candi);
                        // update the head and tail
                      head = head + tail + 1;  // update the head to new uncheck string
                      tail = 0;
                   }
                     // case meet the end of rhs string ( length = head + tail )
                   if( (head + tail) == LLtableRule[i].size()) {
                      string candi = LLtableRule[i].substr(head,tail);
                      temp.push_back(candi);
                       // update the head and tail
                      head = head + tail + 1;  // update the head to new uncheck string
                      tail = 0;
                   }
               }
               // pop top element out of stack
               tree.push_back( TreeNode(stackList[stackTop].getNum(),stackList[stackTop].getData()) );
               stackList.pop_back(); // pop element out
               stackTop = stackList.size()-1;
               treeLevel++; //update treeLevel
               for(int j=temp.size()-1;j>=0;j--){
                   stackList.push_back( Node(temp[j],treeLevel) );
               }
               stackTop = stackList.size()-1;
            }
        }
        if(stackList[stackTop].getData().compare(mainC[mainTop])==0){
            int specFlag = 0;
            int levelNum;
            tree.push_back( TreeNode(stackList[stackTop].getNum(),stackList[stackTop].getData()) );
             //handle id & num case
            if(stackList[stackTop].getData().compare("num")==0 || stackList[stackTop].getData().compare("id")==0){
               specFlag = 1;
               levelNum = stackList[stackTop].getNum()+1;
            }
            stackList.pop_back();
             // update the top pointer
            stackTop = stackList.size()-1;
            mainTop++;
            if(specFlag == 1){
               tree.push_back( TreeNode(levelNum,mainC[mainTop]) );
               //if(mainTop < mainC.size()-1)
               mainTop++;
            }
            treeLevel = stackList[stackTop].getNum();
        }
         // handle stack top is epsilon case
        if(stackList[stackTop].getData().compare("epsilon")==0){
            tree.push_back( TreeNode(stackList[stackTop].getNum(),stackList[stackTop].getData()) );
            stackList.pop_back();
            stackTop = stackList.size()-1; //update
            treeLevel = stackList[stackTop].getNum();
        }
        if(stackList[stackTop].getData().compare("$")==0){
           tree.push_back( TreeNode(stackList[stackTop].getNum(),stackList[stackTop].getData()) );
           stackList.pop_back();
           stackTop = stackList.size()-1;
           treeLevel = stackList[stackTop].getNum();
        }
        if(stackTop == -1){
           i=LLtableNon.size(); // break for loop
        }
     }
  }

  //code geration
  //process symbol table
  //line2 : line for input string(main.c)
  string line2;
  // the line number
  int lineNum = 0;
  int scopeNum = 0;
  while( getline(fileIn3,line2) ){
     int head = 0 , end = 0;
     for(int i=0;i<line2.size();i++){
       if(line2[i]=='\t')
          head++;
       else
          i = line2.size();
     }
     while( head+end <= line2.size() ){
         if(line2.substr(head+end,1).compare(" ")!=0 && (head+end)<line2.size()){ //not white space
             end++;
         }
         else{
           mainLine[lineNum].push_back(line2.substr(head,end));
           head = head + end + 1;
           end = 0;
         }
     }
     // update line number in order to store next new line
     lineNum++;
  }
  // construct symbol table
  for(int i=0;i<lineNum;i++){
     for(int j=0;j<mainLine[i].size();j++){
        // check the scope
        if(mainLine[i][j].compare("{")==0 || mainLine[i][j].compare("(")==0)
           scopeNum++;
        if(mainLine[i][j].compare("}")==0 || mainLine[i][j].compare(")")==0)
           scopeNum--;
        // check the token is double 
        if(mainLine[i][j].compare("double")==0){
           //j+1 => identifier , j+2 => array or function
           int arrFlag = 0, funcFlag = 0;
           string size = "null";
           if(mainLine[i][j+2].compare("[")==0 && mainLine[i][j+4].compare("]")==0){ // array format : int array [ 10 ]
              arrFlag = 1;
              size = mainLine[i][j+3];
           }
           if(mainLine[i][j+2].compare("(")==0 && mainLine[i][mainLine[i].size()-1].compare(")")==0) //function format
              funcFlag = 1;
            
           symbolTable.push_back( Node2(scopeNum,mainLine[i][j+1],mainLine[i][j],arrFlag,funcFlag,size) );
        }
        if(mainLine[i][j].compare("int")==0){
           //j+1 => identifier , j+2 => array or function
           int arrFlag = 0, funcFlag = 0;
           string size = "null";
           if(mainLine[i][j+2].compare("[")==0 && mainLine[i][j+4].compare("]")==0){ // array format : int array [ 10 ]
              arrFlag = 1;
              size = mainLine[i][j+3];
           }
           if(mainLine[i][j+2].compare("(")==0 && mainLine[i][mainLine[i].size()-1].compare(")")==0) //function format
              funcFlag = 1;
 
           symbolTable.push_back( Node2(scopeNum,mainLine[i][j+1],mainLine[i][j],arrFlag,funcFlag,size) );
 
        }
     }
  
  }

  fileOut << "Symbol\tType\tScope\tArray\tFunction" <<endl;
  for(int i=0;i<symbolTable.size();i++){
     fileOut << symbolTable[i].getSymbol() << "\t" << symbolTable[i].getType() << "\t" << symbolTable[i].getScope() << "\t";
     if(symbolTable[i].getArray()==1)
        fileOut << "Ture\t";
     else
        fileOut << "False\t";
     if(symbolTable[i].getFunction()==1)
        fileOut << "True ";
     else
        fileOut << "False ";
     fileOut << endl;
  }
 
  // type checking
  for(int i=0;i<lineNum;i++){
     for(int j=0;j<mainLine[i].size();j++){
        // get the operator =
        if(mainLine[i][j].compare("=")==0){
           if( (mainLine[i].size()-j-1)>2 ){ // right side has more than one token
              string leftType = "null" , rightType = "null";
              int rIdFlag = 0, curScop = 0;
              // handle left one
              for(int k=0;k<symbolTable.size();k++){
                 if(mainLine[i][j-1].compare(symbolTable[k].getSymbol())==0){ // get the identifier
                    leftType = symbolTable[k].getType();
                    curScop = symbolTable[k].getScope();
                 }
              }
              // handle right one, more than one token
              string tempType = "int";  // this version is a simple version( int,double )
              for(int m=j+1;m<mainLine[i].size();m++){
                 // check token is not operator(+,-,*,/,%), ( , )
                 if(mainLine[i][m].compare("+")!=0 && mainLine[i][m].compare("-")!=0 && mainLine[i][m].compare("*")!=0 &&
                    mainLine[i][m].compare("/")!=0 && mainLine[i][m].compare("<")!=0 && mainLine[i][m].compare("(")!=0 &&
                    mainLine[i][m].compare(")")!=0 && mainLine[i][m].compare("<=")!=0 && mainLine[i][m].compare(">")!=0 &&
                    mainLine[i][m].compare(">=")!=0 && mainLine[i][m].compare("&&")!=0 && mainLine[i][m].compare("||")!=0 &&
                    mainLine[i][m].compare("==")!=0 && mainLine[i][m].compare("!=")!=0){
                     for(int k=0;k<symbolTable.size();k++){
                        if(mainLine[i][m].compare(symbolTable[k].getSymbol())==0){ // get the identifier
                           rightType = symbolTable[k].getType();
                           rIdFlag = 1;
                        }
                     }
                     if(rIdFlag == 0){  //not identifer
                        rightType = numDFASym(mainLine[i][m]);
                     }
                     // simple version( int double )
                     if(rightType.compare("double")==0)
                        tempType = rightType;
                 }
              }
              // compare left one type and right one type
              if(leftType.compare(rightType)!=0 && leftType.compare("null")!=0 && rightType.compare("null")!=0){  // not equal
                  cout << "warning (scope" << curScop << ") : " << mainLine[i][j-1] << " " << leftType << ",";
                  cout << "temp" << " " << tempType << endl;
              }
 
           }else{ // right side is only one token
              string leftType = "null", rightType = "null";
              int curScop = 0, rIdFlag = 0;
 
              for(int k=0;k<symbolTable.size();k++){
                  // handle left one
                  if(mainLine[i][j-1].compare(symbolTable[k].getSymbol())==0){ // get the identifier
                     leftType = symbolTable[k].getType();
                     curScop = symbolTable[k].getScope();
                  }
                  // handle right one
                  for(int k=0;k<symbolTable.size();k++){
                     if(mainLine[i][j+1].compare(symbolTable[k].getSymbol())==0){ // get the identifier
                        rightType = symbolTable[k].getType();
                        rIdFlag = 1;
                     }
                  }
                  if(rIdFlag == 0){  //not identifer
                     rightType = numDFASym(mainLine[i][j+1]);
                  }
              }
              if(leftType.compare(rightType)!=0 && leftType.compare("null")!=0 && rightType.compare("null")!=0){  // not equal
                  cout << "warning (scope" << curScop << ") : " << mainLine[i][j-1] << " " << leftType << ",";
                  cout << mainLine[i][j+1] << " " << rightType << endl;
              }
  
           }
           // break this line
           j = mainLine[i].size()-1;
        }
         
     }
 
  }
 
  int traceLevel = 1;  // store the trace tree level num
  int notFinish = 1;
  
  while(notFinish){
     int notFind = 1;  
     for(int i=0;i<tree.size();i++){
         if(tree[i].getTreeLevel() == traceLevel){

             notFind *= 0;
         }
     }
     if(notFind==0){
        traceLevel++;
     }else{ // tree level is max, don't have larger level number
        notFinish = 0; //break while loop
     }

  }
  
  fileOut2 << "@.str = private unnamed_addr constant [4 x i8] c\"%d\\0A\\00\", align 1" << endl;
  fileOut2 << "@.str1 = private unnamed_addr constant [4 x i8] c\"%f\\0A\\00\", align 1" << endl;
  fileOut2 << "declare i32 @printf(i8*, ...)" << endl;

  S(0,1);
 
}
 
  
void numDFA(string inputstr){
     // number string length
    int count = 0;
     
    if(inputstr.substr(0,1).compare("0")==0 || inputstr.substr(0,1).compare("1")==0 || inputstr.substr(0,1).compare("2")==0 ||
       inputstr.substr(0,1).compare("3")==0 || inputstr.substr(0,1).compare("4")==0 || inputstr.substr(0,1).compare("5")==0 ||
       inputstr.substr(0,1).compare("6")==0 || inputstr.substr(0,1).compare("7")==0 || inputstr.substr(0,1).compare("8")==0 ||
       inputstr.substr(0,1).compare("9")==0 ){
        count++;
    }
     // check other of the string is a number or not
    for(int i=1;i<inputstr.length();i++){
       if(inputstr.substr(i,1).compare("0")==0 || inputstr.substr(i,1).compare("1")==0 || inputstr.substr(i,1).compare("2")==0 ||
          inputstr.substr(i,1).compare("3")==0 || inputstr.substr(i,1).compare("4")==0 || inputstr.substr(i,1).compare("5")==0 ||
          inputstr.substr(i,1).compare("6")==0 || inputstr.substr(i,1).compare("7")==0 || inputstr.substr(i,1).compare("8")==0 ||
          inputstr.substr(i,1).compare("9")==0 || inputstr.substr(i,1).compare(".")==0 ){
           count++;
       }
    }
   if(inputstr.size() != 0 && count == inputstr.size()){
       mainC.push_back("num");
       mainC.push_back(inputstr);
   }
}
     
void idDFA(string inputstr){
     // id string length
    int count = 0;
     
    if(inputstr.substr(0,1).compare("a")==0 || inputstr.substr(0,1).compare("b")==0 || inputstr.substr(0,1).compare("c")==0 ||
       inputstr.substr(0,1).compare("d")==0 || inputstr.substr(0,1).compare("e")==0 || inputstr.substr(0,1).compare("f")==0 ||
       inputstr.substr(0,1).compare("g")==0 || inputstr.substr(0,1).compare("h")==0 || inputstr.substr(0,1).compare("i")==0 ||
       inputstr.substr(0,1).compare("j")==0 || inputstr.substr(0,1).compare("k")==0 || inputstr.substr(0,1).compare("l")==0 ||
       inputstr.substr(0,1).compare("m")==0 || inputstr.substr(0,1).compare("n")==0 || inputstr.substr(0,1).compare("o")==0 ||
       inputstr.substr(0,1).compare("p")==0 || inputstr.substr(0,1).compare("q")==0 || inputstr.substr(0,1).compare("r")==0 ||
       inputstr.substr(0,1).compare("s")==0 || inputstr.substr(0,1).compare("t")==0 || inputstr.substr(0,1).compare("u")==0 ||
       inputstr.substr(0,1).compare("v")==0 || inputstr.substr(0,1).compare("w")==0 || inputstr.substr(0,1).compare("x")==0 ||
       inputstr.substr(0,1).compare("y")==0 || inputstr.substr(0,1).compare("z")==0 || inputstr.substr(0,1).compare("A")==0 ||
       inputstr.substr(0,1).compare("B")==0 || inputstr.substr(0,1).compare("C")==0 || inputstr.substr(0,1).compare("D")==0 ||
       inputstr.substr(0,1).compare("E")==0 || inputstr.substr(0,1).compare("F")==0 || inputstr.substr(0,1).compare("G")==0 ||
       inputstr.substr(0,1).compare("H")==0 || inputstr.substr(0,1).compare("I")==0 || inputstr.substr(0,1).compare("J")==0 ||
       inputstr.substr(0,1).compare("K")==0 || inputstr.substr(0,1).compare("L")==0 || inputstr.substr(0,1).compare("M")==0 ||
       inputstr.substr(0,1).compare("N")==0 || inputstr.substr(0,1).compare("O")==0 || inputstr.substr(0,1).compare("P")==0 ||
       inputstr.substr(0,1).compare("Q")==0 || inputstr.substr(0,1).compare("R")==0 || inputstr.substr(0,1).compare("S")==0 ||
       inputstr.substr(0,1).compare("T")==0 || inputstr.substr(0,1).compare("U")==0 || inputstr.substr(0,1).compare("V")==0 ||
       inputstr.substr(0,1).compare("W")==0 || inputstr.substr(0,1).compare("X")==0 || inputstr.substr(0,1).compare("Y")==0 ||
       inputstr.substr(0,1).compare("Z")==0 || inputstr.substr(0,1).compare("_")==0 ){
        count++;
        for(int i=1;i<inputstr.length();i++){
          if(inputstr.substr(i,1).compare("a")==0 || inputstr.substr(i,1).compare("b")==0 || inputstr.substr(i,1).compare("c")==0 ||
             inputstr.substr(i,1).compare("d")==0 || inputstr.substr(i,1).compare("e")==0 || inputstr.substr(i,1).compare("f")==0 ||
             inputstr.substr(i,1).compare("g")==0 || inputstr.substr(i,1).compare("h")==0 || inputstr.substr(i,1).compare("i")==0 ||
             inputstr.substr(i,1).compare("j")==0 || inputstr.substr(i,1).compare("k")==0 || inputstr.substr(i,1).compare("l")==0 ||
             inputstr.substr(i,1).compare("m")==0 || inputstr.substr(i,1).compare("n")==0 || inputstr.substr(i,1).compare("o")==0 ||
             inputstr.substr(i,1).compare("p")==0 || inputstr.substr(i,1).compare("q")==0 || inputstr.substr(i,1).compare("r")==0 ||
             inputstr.substr(i,1).compare("s")==0 || inputstr.substr(i,1).compare("t")==0 || inputstr.substr(i,1).compare("u")==0 ||
             inputstr.substr(i,1).compare("v")==0 || inputstr.substr(i,1).compare("w")==0 || inputstr.substr(i,1).compare("x")==0 ||
             inputstr.substr(i,1).compare("y")==0 || inputstr.substr(i,1).compare("z")==0 || inputstr.substr(i,1).compare("A")==0 ||
             inputstr.substr(i,1).compare("B")==0 || inputstr.substr(i,1).compare("C")==0 || inputstr.substr(i,1).compare("D")==0 ||
             inputstr.substr(i,1).compare("E")==0 || inputstr.substr(i,1).compare("F")==0 || inputstr.substr(i,1).compare("G")==0 ||
             inputstr.substr(i,1).compare("H")==0 || inputstr.substr(i,1).compare("I")==0 || inputstr.substr(i,1).compare("J")==0 ||
             inputstr.substr(i,1).compare("K")==0 || inputstr.substr(i,1).compare("L")==0 || inputstr.substr(i,1).compare("M")==0 ||
             inputstr.substr(i,1).compare("N")==0 || inputstr.substr(i,1).compare("O")==0 || inputstr.substr(i,1).compare("P")==0 ||
             inputstr.substr(i,1).compare("Q")==0 || inputstr.substr(i,1).compare("R")==0 || inputstr.substr(i,1).compare("S")==0 ||
             inputstr.substr(i,1).compare("T")==0 || inputstr.substr(i,1).compare("U")==0 || inputstr.substr(i,1).compare("V")==0 ||
             inputstr.substr(i,1).compare("W")==0 || inputstr.substr(i,1).compare("X")==0 || inputstr.substr(i,1).compare("Y")==0 ||
             inputstr.substr(i,1).compare("Z")==0 || inputstr.substr(i,1).compare("0")==0 || inputstr.substr(i,1).compare("1")==0 ||
             inputstr.substr(i,1).compare("2")==0 || inputstr.substr(i,1).compare("3")==0 || inputstr.substr(i,1).compare("4")==0 ||
             inputstr.substr(i,1).compare("5")==0 || inputstr.substr(i,1).compare("6")==0 || inputstr.substr(i,1).compare("7")==0 ||
             inputstr.substr(i,1).compare("8")==0 || inputstr.substr(i,1).compare("9")==0 || inputstr.substr(i,1).compare("_")==0)
               count++;
       }
    }
      // string is not empty
    if( inputstr.size() != 0 && count == inputstr.size() ){
       mainC.push_back("id");
       mainC.push_back(inputstr);
    }
}
 
string numDFASym(string inputstr){
     // number string length
    int count = 0, doubleFlag = 0;
 
    if(inputstr.substr(0,1).compare("0")==0 || inputstr.substr(0,1).compare("1")==0 || inputstr.substr(0,1).compare("2")==0 ||
       inputstr.substr(0,1).compare("3")==0 || inputstr.substr(0,1).compare("4")==0 || inputstr.substr(0,1).compare("5")==0 ||
       inputstr.substr(0,1).compare("6")==0 || inputstr.substr(0,1).compare("7")==0 || inputstr.substr(0,1).compare("8")==0 ||
       inputstr.substr(0,1).compare("9")==0 ){
         count++;
    }
    for(int i=1;i<inputstr.length();i++){
       if(inputstr.substr(i,1).compare("0")==0 || inputstr.substr(i,1).compare("1")==0 || inputstr.substr(i,1).compare("2")==0 ||
          inputstr.substr(i,1).compare("3")==0 || inputstr.substr(i,1).compare("4")==0 || inputstr.substr(i,1).compare("5")==0 ||
          inputstr.substr(i,1).compare("6")==0 || inputstr.substr(i,1).compare("7")==0 || inputstr.substr(i,1).compare("8")==0 ||
          inputstr.substr(i,1).compare("9")==0 || inputstr.substr(i,1).compare(".")==0 ){
            count++;
            if(inputstr.substr(i,1).compare(".")==0)
                doubleFlag = 1;
       }
    }
   if(inputstr.size() != 0 && count == inputstr.size()){
       if(doubleFlag == 1) // is double number
          return "double";
       else
          return "int";
   }else{
      return "false";
   }
}

string itos(int x){
   string s;
   stringstream ss(s);
   ss << x;
   return ss.str();
}


//Code generation function
  
//This function is OK
void S(int index,int treeLevel){
   Program(index+1,tree[index+1].getTreeLevel());
}
  
//This function is OK
void Program(int index,int treeLevel){
   DeclList(index+1,tree[index+1].getTreeLevel());
}
  
//THis function is OK
void DeclList(int index,int treeLevel){
   for(int i=index;i<tree.size();i++){
      if(tree[i].getTreeLevel() == treeLevel+1){
         //DeclList -> epsilon case do nothing
         if(tree[i].getTreeNode().compare("DeclList'")==0){
             DeclList1(i,tree[i].getTreeLevel());
             for(int j=i+1;j<tree.size();j++){
                if(tree[j].getTreeLevel() == treeLevel+1)
                   if(tree[j].getTreeNode().compare("DeclList")==0){
                       DeclList(j,tree[j].getTreeLevel());
                       j = tree.size();  //break loop
                   }
             }
             i = tree.size();
         }
         //end of case: DeclList -> DeclList' CeclList
      }
   }
}
  
//This function is OK except FunDecl case
void DeclList1(int index,int treeLevel){
    string type = "null", id = "null" , decl = "null";
    for(int i=index;i<tree.size();i++){
       if(tree[i].getTreeLevel() == treeLevel+1){
          if(tree[i].getTreeNode().compare("Type")==0){
             type = Type(i+1,tree[i].getTreeLevel());
             for(int j=i+1;j<tree.size();j++){
                if(tree[j].getTreeLevel()==treeLevel+1){
                  if(tree[j].getTreeNode().compare("id")==0){
                     id = Id(j+1,tree[j].getTreeLevel());
                     for(int k=j+1;k<tree.size();k++){
                       if(tree[k].getTreeLevel()==treeLevel+1){
                         if(tree[k].getTreeNode().compare("Decl")==0){
                            if(tree[k+1].getTreeNode().compare("FunDecl")==0){
                               fileOut2 << "define ";
                               if(type.compare("int")==0) // integer
                                  fileOut2 << "i32 @" << id;
                               else
                                  fileOut2 << "double @" << id;
                            }
                            decl = Decl(i+1,tree[i].getTreeLevel());
                            k =tree.size();
                         }
                       }
                     }
                     j =tree.size();
                  }
                }
             }
             i = tree.size();
          }
       }
    }

    //handle information
    if(type.compare("null")!=0 && id.compare("null")!=0 && decl.compare("null")!=0){
        if(decl.compare(";")==0){  // Decl->VarDecl' and VarDecl'-> ;
           int scope = 0;
           for(int j=0;j<symbolTable.size();j++){
              if(id.compare(symbolTable[j].getSymbol())==0)
                scope = symbolTable[j].getScope();
           }
           if(scope == 0){  // global variable
              fileOut2 << "@" << id << " = common global ";
              if(type.compare("int")==0) // integer
                 fileOut2 << "i32 0, align 4" << endl;
              else
                 fileOut2 << "double 0.0, align 8" << endl;
           }
           else{ //local variable
              fileOut2 << "%" << id << " = alloca ";
              if(type.compare("int")==0) // integer
                 fileOut2 << "i32, align 4" << endl;
              else
                 fileOut2 << "double, align 8" << endl;
           }
        }
        else { //array case ; Decl -> VarDecl' and VarDecl' -> [ num ] (array)
         // vardecl' is a num so decl is a num
           int scope = 0;
           for(int j=0;j<symbolTable.size();j++){
              if(id.compare(symbolTable[j].getSymbol())==0)
                scope = symbolTable[j].getScope();
           }
           if(scope == 0){  // global variable
              fileOut2 << "@" << id << " = common global ";
              if(type.compare("int")==0) // integer
                 fileOut2 << "[" << decl << " x i32] zeroinitializer, align 16" << endl;
              if(type.compare("double")==0)
                 fileOut2 << "[" << decl << " x double] zeroinitializer, align 16" << endl;
           }
           else{   //local variable
              fileOut2 << "%" << id << " = alloca ";
              if(type.compare("int")==0) // integer
                 fileOut2 << "[" << decl << " x i32], align 16" << endl;
              if(type.compare("double")==0)
                 fileOut2 << "[" << decl << " x double], align 16" << endl;
           }
        }
    }
}
  
//This function design is OK, but result maybe not correct
string Decl(int index,int treeLevel){
   string vardecl1 = "null", fundecl = "null";
   for(int i=0;i<tree.size();i++){
      if(tree[i].getTreeLevel() == treeLevel+1){
         //case: Decl -> VarDecl'
         if(tree[i].getTreeNode().compare("VarDecl'")==0){
            vardecl1 = VarDecl1(i+1,tree[i].getTreeLevel());
            //i = tree.size();
         }
         //Case: Decl -> FunDecl
         if(tree[i].getTreeNode().compare("FunDecl")==0){
            //Case of FunDecl do nothing so return null
             fundecl = FunDecl(i+1,tree[i].getTreeLevel());
             //i = tree.size();
         }
      }
   }
   if(vardecl1.compare("null")!=0)
      return vardecl1;
   else
      return fundecl;
}
  
//This function is OK!
void VarDecl(int index,int treeLevel){
    string type = "null", id = "null" , vardecl1 = "null";
    for(int i=index;i<tree.size();i++){
       if(tree[i].getTreeLevel() == treeLevel+1){
          if(tree[i].getTreeNode().compare("Type")==0){
             type = Type(i+1,tree[i].getTreeLevel());
             for(int j=i+1;j<tree.size();j++){
                if(tree[j].getTreeLevel()==treeLevel+1){
                  if(tree[j].getTreeNode().compare("id")==0){
                     id = Id(j+1,tree[j].getTreeLevel());
                     for(int k=j+1;k<tree.size();k++){
                       if(tree[k].getTreeLevel()==treeLevel+1){
                         if(tree[k].getTreeNode().compare("VarDecl'")==0){
                            vardecl1 = VarDecl1(k+1,tree[k].getTreeLevel());
                            k =tree.size();
                         }
                       }
                     }
                     j =tree.size();
                  }
                }
             }
             i = tree.size();
          }
       }
    }
    //handle information
    if(type.compare("null")!=0 && id.compare("null")!=0 && vardecl1.compare("null")!=0){
        if(vardecl1.compare(";")==0){  //Decl -> VarDecl' and  VarDecl'-> ;
          int scope = 0;
           for(int j=0;j<symbolTable.size();j++){
              if(id.compare(symbolTable[j].getSymbol())==0)
                scope = symbolTable[j].getScope();
           }
           if(scope == 0){  // global variable
              fileOut2 << "@" << id << " = common global ";
              if(type.compare("int")==0) // integer
                 fileOut2 << "i32 0, align 4" << endl;
              else
                 fileOut2 << "double 0.0, align 8" << endl;

           }
           else{  //local variable
              fileOut2 << "%" << id << " = alloca ";
              if(type.compare("int")==0) // integer
                 fileOut2 << "i32, align 4" << endl;
              else
                 fileOut2 << "double, align 8" << endl;
           }
        }
        // array case
        //Decl->VarDecl' and VarDecl'->[ num ] ; (array)
        else{   // vardecl1 is a number
           int scope = 0;
           for(int j=0;j<symbolTable.size();j++){
              if(id.compare(symbolTable[j].getSymbol())==0)
                scope = symbolTable[j].getScope();
           }
           if(scope == 0){  // global variable
              fileOut2 << "@" << id << " = common global ";
              if(type.compare("int")==0) // integer
                 fileOut2 << "[" << vardecl1 << " x i32] zeroinitializer, align 16" << endl;
              if(type.compare("double")==0)
                 fileOut2 << "[" << vardecl1 << " x double] zeroinitializer, align 16" << endl;
           }
           else{ //local variable
              fileOut2 << "%" << id << " = alloca ";
              if(type.compare("int")==0) // integer
                 fileOut2 << "[" << vardecl1 << " x i32], align 16" << endl;
              if(type.compare("double")==0)
                 fileOut2 << "[" << vardecl1 << " x double], align 16" << endl;
           }
        }
    }
}
  
//This function is OK!
string VarDecl1(int index,int treeLevel){
   if(tree[index].getTreeLevel() == treeLevel+1){
      //case: VarDecl' -> ;
      if(tree[index].getTreeNode().compare(";")==0)
         return ";";
      //case: VarDecl' -> [ num ] ;
      if(tree[index].getTreeNode().compare("[")==0){
         string num;
         num = Num(index+2,tree[index+1].getTreeLevel());
         return num;
      }
   }
}
  
//This function maybe OK
string FunDecl(int index,int treeLevel){
  // this function is't implement
  for(int i=index;i<tree.size();i++){
      if(tree[i].getTreeLevel() == treeLevel+1){ //FunDecl -> ( ParamDeclList ) BLock
          if(tree[i].getTreeNode().compare("(")==0){
             fileOut2 << "(";
             ParamDeclList(i+1,tree[i].getTreeLevel());
             fileOut2 << ") #0";
             for(int j=i+2;j<tree.size();j++){
                if(tree[j].getTreeLevel() == treeLevel+1){
                   if(tree[j].getTreeNode().compare("Block")==0){
                       Block(j+1,tree[j].getTreeLevel());
                       j= tree.size(); //break loop
////////////////////////////////////////////////////////////////////////////change block
                   }
                }
             }
             i = tree.size();   //
          }
      }
  }
  return "null";
}
  
//This function is OK
void VarDeclList(int index,int treeLevel){
   for(int i=index;i<tree.size();i++){
      if(tree[i].getTreeLevel() == treeLevel+1){
          //Case : VarDeclList -> VarDecl VarDeclList
          if(tree[i].getTreeNode().compare("VarDecl")==0){
              VarDecl(i+1,tree[i].getTreeLevel());
              for(int j=i+1;j<tree.size();j++){
                 if(tree[j].getTreeLevel() == treeLevel+1){
                    if(tree[j].getTreeNode().compare("VarDeclList")==0){
                        VarDeclList(j+1,tree[j].getTreeLevel());
                        j = tree.size(); // break j loop
                     }
                 }
              }
              i = tree.size(); // break i loop
          }
          // VarDeclList -> epsilon  doesn't need to implement
      }
   }
}
  
//This function is OK
//This function : handle parameter for function ex: XXX( _handle this__ )
void ParamDeclList(int index,int treeLevel){
   for(int i=index;i<tree.size();i++){
      if(tree[i].getTreeLevel() == treeLevel+1){
          //Case : ParamDeclList -> ParamDeclListTail
          if(tree[i].getTreeNode().compare("ParamDeclListTail")==0){
              ParamDeclListTail(i+1,tree[i].getTreeLevel());
              i = tree.size();
          }
          // ParamDeclList -> epsilon dosen't need to implement
      }
   }
}
  
//This function : parameters ex: XX( int a ,double b)
void ParamDeclListTail(int index,int treeLevel){
   for(int i=index;i<tree.size();i++){
      if(tree[i].getTreeLevel() == treeLevel+1){
          //Case : ParamDeclListTail -> ParamDecl ParamDeclListTail'
          if(tree[i].getTreeNode().compare("ParamDecl")==0){
              ParamDecl(i+1,tree[i].getTreeLevel());
              for(int j=i+1;j<tree.size();j++){
                 if(tree[j].getTreeLevel() == treeLevel+1){
                    if(tree[j].getTreeNode().compare("ParamDeclListTail'")==0){
                        ParamDeclListTail1(j+1,tree[j].getTreeLevel());
                        j = tree.size();
                    }
                 }
              }
              i = tree.size();
          }
      }
   }
}
  
//This function is OK
void ParamDeclListTail1(int index,int treeLevel){
   for(int i=index;i<tree.size();i++){
      if(tree[i].getTreeLevel() == treeLevel+1){
          //Case : ParamDeclListTail' -> , ParamDeclListTail
          //for another parameter
          if(tree[i].getTreeNode().compare(",")==0){
              fileOut2 << " , ";
              ParamDeclListTail(i+2,tree[i].getTreeLevel());
          }
          // ParamDeclList -> epsilon dosen't need to implement
      }
      i = tree.size();
   }
}
  
void ParamDecl(int index,int treeLevel){
    string type = "null", id = "null" , paramdecl1 = "null";
    for(int i=index;i<tree.size();i++){
       if(tree[i].getTreeLevel() == treeLevel+1){
          if(tree[i].getTreeNode().compare("Type")==0){
             type = Type(i+1,tree[i].getTreeLevel());
             for(int j=i+1;j<tree.size();j++){
                if(tree[j].getTreeLevel()==treeLevel+1){
                  if(tree[j].getTreeNode().compare("id")==0){
                     id = Id(j+1,tree[j].getTreeLevel());
                     for(int k=j+1;k<tree.size();k++){
                       if(tree[k].getTreeLevel()==treeLevel+1){
                         if(tree[k].getTreeNode().compare("ParamDecl'")==0){
                            paramdecl1 = ParamDecl1(k+1,tree[k].getTreeLevel());
                            k =tree.size();
                         }
                       }
                     }
                     j =tree.size();
                  }
                }
             }
             i = tree.size();
          }
       }
    }
    if(type.compare("null")!=0 && id.compare("null")!=0 && paramdecl1.compare("null")!=0){
    if(paramdecl1.compare("epsilon")==0){
       funcParamNum++;
       if(type.compare("int")==0)
          fileOut2 << "i32 %" << id;
       if(type.compare("double")==0)
          fileOut2 << "double %" << id;
       funcParam.push_back(Node3(funcParamNum,type,0,id));
    }
    else{  //array case
       funcParamNum++;
       if(type.compare("int")==0)
          fileOut2 << "i32* %" << id;
       if(type.compare("double")==0)
          fileOut2 << "double* %" << id;
       funcParam.push_back(Node3(funcParamNum,type,1,id));
    }
    }
}

//////
  
//This function is OK
string ParamDecl1(int index,int treeLevel){
    for(int i=index;i<tree.size();i++){
       if(tree[i].getTreeLevel() == treeLevel+1){
          if(tree[i].getTreeNode().compare("epsilon")==0)
             return "epsilon";
          //Case : array
          if(tree[i].getTreeNode().compare("[")==0)
             return "array";
       }
    }
}
  
//This function is OK
void Block(int index,int treeLevel) {
    for(int i=index;i<tree.size();i++){
       if(tree[i].getTreeLevel() == treeLevel+1){
          //Case: Block -> { VarDeclList StmtList }
          if(tree[i].getTreeNode().compare("{")==0){ // {:i , VarDeclList:i+1
             fileOut2 << " {" << endl;
// tempRegNum must reset
             tempRegNum = 1;
             int paramCount =0;
             while(funcParamNum>0){
                fileOut2 << "%" << itos(tempRegNum) << " = alloca ";
                if(funcParam[paramCount].getType().compare("int")==0){
                   fileOut2 << "i32";
                   if(funcParam[paramCount].getArray() == 0){ //not array
                      fileOut2 << ", align 4" << endl;
                      fileOut2 << "store i32 %" << funcParam[paramCount].getId() << ", i32* %"<<itos(tempRegNum)<<", align 4" <<endl;
                   }
                   if(funcParam[paramCount].getArray() == 1){
                      fileOut2 << "*, align 8" << endl;
                      fileOut2 << "store i32* %"<<funcParam[paramCount].getId()<<", i32** %"<<itos(tempRegNum)<<", align 8"<< endl;
                   }
                }
                if(funcParam[paramCount].getType().compare("double")==0){
                   fileOut2 << "double";
                   if(funcParam[paramCount].getArray() == 0){ //not array
                      fileOut2 << ", align 8" << endl;
                      fileOut2 <<"store double %"<<funcParam[paramCount].getId()<<", double* %"<<itos(tempRegNum)<<", align 8" <<endl;
                   }
                   if(funcParam[paramCount].getArray() == 1){
                      fileOut2 << "*, align 8" << endl;
                      fileOut2 <<"store double* %"<<funcParam[paramCount].getId()<<", double** %"<<itos(tempRegNum)<<", align 8"<<endl;
                   }
                }
                for(int z=0;z<symbolTable.size();z++){
                   if(funcParam[paramCount].getId().compare(symbolTable[z].getSymbol())==0)
                      symbolTable[z].setParam(tempRegNum);
                }
                tempRegNum++;
                paramCount++;
                funcParamNum--;
             }
             while(funcParam.size()>0){
                funcParam.pop_back();
             }
             VarDeclList(i+2,tree[i].getTreeLevel());
             for(int j=i+2;j<tree.size();j++){
                if(tree[j].getTreeNode().compare("StmtList")==0){
                   StmtList(j+1,tree[j].getTreeLevel());
                   fileOut2 << endl << "}" << endl;
                   j = tree.size();
                }
             }
             i = tree.size();
          }
          //End of case  
       }
    }
}
  
//This function is OK
string Type(int index,int treeLevel){
   if(tree[index].getTreeLevel() == treeLevel+1){
       if(tree[index].getTreeNode().compare("int")==0)
           return "int";
       if(tree[index].getTreeNode().compare("double")==0)
           return "double";
       if(tree[index].getTreeNode().compare("char")==0)
           return "char";
       if(tree[index].getTreeNode().compare("float")==0)
           return "float";
   }
}
  
//This function is OK
void StmtList(int index,int treeLevel){
    for(int i=index;i<tree.size();i++){
       if(tree[i].getTreeLevel() == treeLevel+1){
          if(tree[i].getTreeNode().compare("Stmt")==0){
             Stmt(i+1,tree[i].getTreeLevel());
             for(int j=i+1;j<tree.size();j++){
                 if(tree[j].getTreeLevel() == treeLevel+1){
                    if(tree[j].getTreeNode().compare("StmtList'")==0){
                        StmtList1(j+1,tree[j].getTreeLevel());
                        j = tree.size(); // break loop
                     }
                 }
             }
             i = tree.size(); //break i loop
          }
          //end of case
       }
    }
}
  
//This function is OK
void StmtList1(int index,int treeLevel){
    for(int i=index;i<tree.size();i++){
       if(tree[i].getTreeLevel() == treeLevel+1){
          if(tree[i].getTreeNode().compare("StmtList")==0)
             StmtList(i+1,tree[i].getTreeLevel());
       }
    }
}
  
void Stmt(int index,int treeLevel){
    for(int i=index;i<tree.size();i++){
        if(tree[i].getTreeLevel()==treeLevel+1){
            //Case: Stmt -> Expr;
            if(tree[i].getTreeNode().compare("Expr")==0){
               string expr;
               expr = Expr(i+1,tree[i].getTreeLevel());
              // return;  expr don't use it
            }
            //Case: Stmt -> return Expr ;
            if(tree[i].getTreeNode().compare("return")==0){
               string expr;
               for(int j=i+1;j<tree.size();j++){
                  if(tree[j].getTreeLevel() == treeLevel+1){
                     if(tree[j].getTreeNode().compare("Expr")==0){
                         expr = Expr(j+1,tree[j].getTreeLevel());
                      } 
                  }
               }
               //expr is number
               if(numDFASym(expr).compare("double")==0)
                  fileOut2 << "ret double " << expr << endl;
               else
                  fileOut2 << "ret i32 " << expr << endl;
            }//end of this case
            //Case: Stmt -> break;
            //I don't know what to do
              
            //Case: Stmt -> print id
            if(tree[i].getTreeNode().compare("print")==0){
               string type, id;
               // id => i+1
               id = Id(i+2,tree[i+1].getTreeLevel());
               for(int j=0;j<symbolTable.size();j++){
                  if(id.compare(symbolTable[j].getSymbol())==0)
                     type = symbolTable[j].getType();
               }
               //cout << "1777, id = " << id << ", type = " << type << endl;
               if(type.compare("int")==0){  //integer
                  //check id scope ..
                  int scope;
                  int paramReg;
                  for(int l=0;l<symbolTable.size();l++){
                     if(id.compare(symbolTable[l].getSymbol())==0){
                        scope = symbolTable[l].getScope();
                        paramReg = symbolTable[l].getParam();
                     }   
                  }
                  if(scope == 0){ //global
                        fileOut2 << "%" << itos(tempRegNum) << " = load i32* @" << id << ", align 4" << endl;
                  }else{  //local
                     if(paramReg == 0)
                        fileOut2 << "%" << itos(tempRegNum) << " = load i32* %" << id << ", align 4" << endl;
                     else
                        fileOut2 << "%" << itos(tempRegNum) << " = load i32* %" << paramReg << ", align 4" << endl;
                  }
                  tempRegNum++;
                  fileOut2 << "%" << itos(tempRegNum) << " = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str, i32 0, i32 0), i32 %" << itos(tempRegNum-1) << ")" << endl;
                  tempRegNum++;
               }if(type.compare("double")==0){ //double
                  //check id scope ..
                  int scope;
                  int paramReg;
                  for(int l=0;l<symbolTable.size();l++){
                     if(id.compare(symbolTable[l].getSymbol())==0){
                       scope = symbolTable[l].getScope();
                       paramReg = symbolTable[l].getParam();
                     }
                  }
                  if(scope == 0){ //global
                     fileOut2 << "%" << itos(tempRegNum) << " = load double* @" << id << ", align 8" << endl;
                  }else{  //local
                     if(paramReg == 0)
                        fileOut2 << "%" << itos(tempRegNum) << " = load double* %" << id << ", align 8" << endl;
                     else
                        fileOut2 << "%" << itos(tempRegNum) << " = load double* %" << paramReg << ", align 8" << endl;
                  }
                  tempRegNum++;
                  fileOut2 << "%" << itos(tempRegNum) << " = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), double %" << itos(tempRegNum-1) << ")" << endl;
                  tempRegNum++;
               }
            }
            //Case: Stmt -> if ( Expr ) Stmt else Stmt
            //Case: Stmt -> Block
            if(tree[i].getTreeNode().compare("Block")==0){
                Block(i+1,tree[i].getTreeLevel());
            }
            i = tree.size(); //break loop
        }
    }
}
  
//This function maybe OK
// I want to get the treelevel and index to check tree[index~tree.size()-1] node which treelevel is current + 1
string Expr1(int index,int treeLevel){
   for(int i=index;i<tree.size();i++){
      if(tree[i].getTreeLevel()==treeLevel+1){
         if(tree[i].getTreeNode().compare("epsilon")==0) // Expr'->epsilon
           return "epsilon";
         else{  // Expr'->BinOp Expr
             string op = "null", expr = "null";
             if(tree[i].getTreeNode().compare("BinOp")==0){
                op = BinOp(i+1,tree[i].getTreeLevel());
                for(int j=i+1;j<tree.size();j++){
                    if(tree[j].getTreeLevel() == treeLevel+1){
                       if(tree[j].getTreeNode().compare("Expr")==0){
                          expr = Expr(j+1,tree[j].getTreeLevel());
                          j = tree.size(); //break loop
                          i = tree.size();
                       }
                    }
                }
                if(op.compare("null")!=0 && expr.compare("null")!=0)
                    return op+" "+expr;
             }
         }
         //End of case
         i = tree.size();
      }
   }
   return "null";
}
  
//This function is OK
string UnaryOp(int index,int treeLevel){
   if(tree[index].getTreeLevel() == treeLevel+1)
      return tree[index].getTreeNode();
}
  
//This function is OK
string BinOp(int index,int treeLevel){
   if(tree[index].getTreeLevel() == treeLevel+1)
      return tree[index].getTreeNode();
}
  
//This function is OK
string Num(int index,int treeLevel){
   if(tree[index].getTreeLevel() == treeLevel+1)
      return tree[index].getTreeNode();
}
  
//This function is OK
string Id(int index,int treeLevel){
   if(tree[index].getTreeLevel() == treeLevel+1)
      return tree[index].getTreeNode();
}  
  
string Expr(int index,int treeLevel){
   for(int i=index;i<tree.size();i++){
      if(tree[i].getTreeLevel()==treeLevel+1){
          if(tree[i].getTreeNode().compare("UnaryOp")==0){ //Expr->UnaryOp Expr
              string unaryop = "null", expr = "null";
              unaryop = UnaryOp(i,tree[i].getTreeLevel());
              // handle second part: find Expr
              for(int j=i+1;j<tree.size();j++){
                 if(tree[j].getTreeLevel()==treeLevel+1){
                    if(tree[j].getTreeNode().compare("Expr")==0)
                        expr = Expr(j+1,tree[j].getTreeLevel());
                 }
              }
              return unaryop+" "+expr;
          }
          if(tree[i].getTreeNode().compare("num")==0){ //Expr->num Expr'
              string num = "null", expr1 = "null";
              num = Num(i+1,tree[i].getTreeLevel());
              // handle second part: find Expr'
              for(int j=i+1;j<tree.size();j++){
                 if(tree[j].getTreeLevel()==treeLevel+1){
                    if(tree[j].getTreeNode().compare("Expr'")==0){
                        expr1 = Expr1(j+1,tree[j].getTreeLevel());
                        j = tree.size(); //break loop
                    }
                 }
              }
              if(num.compare("null")!=0 && expr1.compare("null")!=0){
                 if(expr1.compare("epsilon")==0){
                    return num;
                 }else{ //expr' = op+" "+expr ,expr: %num
                    string op, expr;
                    //split the return string which is op+" "+expr
                    int head=0, end=0;
                    while(head+end < expr1.size()){
                       if(expr1.substr(head+end,1).compare(" ")!=0)
                           end++;
                       else{
                          end = expr1.size();
                          op = expr1.substr(head,end);
                          expr = expr1.substr(end+1,expr1.size()-end-1);
                          fileOut2 << "%" << tempRegNum << " = " << op << " nsw ";
                          if(numDFASym(num).compare("double"))
                             fileOut2 << "double " << num << ", " << expr << endl;
                          else
                             fileOut2 << "i32 " << num << ", " << expr << endl;
                          tempRegNum++; //update
                       }
                    }
                    return "%"+itos(tempRegNum-1);
                 }
              }
          }//End of case: Expr ->  num Expr'
          if(tree[i].getTreeNode().compare("(")==0){ //Expr->( Expr ) Expr'
              string expr = "null", expr1 = "null";
              // Expr index => i+1
              expr = Expr(i+2,tree[i+1].getTreeLevel());
              for(int j=i+2;j<tree.size();j++){
                 if(tree[j].getTreeLevel()==treeLevel+1){
                    if(tree[j].getTreeNode().compare("Expr'")==0){
                        expr1 = Expr1(j,tree[j].getTreeLevel());
                        j = tree.size();
                    }
                 }
              }
              if(expr.compare("null")!=0 && expr1.compare("null")!=0){
                 //Case : Expr' -> epsilon
                 if(expr1.compare("epsilon")==0){
                    return expr;  //expr => regNum+" "+id
                 }else{
                    // expr' => op+" "+id
                    string tempToken;
                    string type1, type2;
                    string exprReg = "null", exprId = "null";
                    string expr1Op = "null", expr1Id = "null";
                    int head=0, end=0, count = 0;
                    int expr1IdRegNum;
                    while(head+end <= expr.size()){
                        if(expr.substr(head+end,1).compare(" ")!=0 && (head+end)<expr.size())
                           end++;
                        else{
                           tempToken = expr.substr(head,end);
                           head = head + end + 1;
                           end = 0;
                           count++;
                        }
                        if(count == 1)
                          exprReg = tempToken;
                        if(count == 2)
                          exprId = tempToken;
                    }
                    // reset 
                    head = 0;
                    end = 0;
                    count = 0;
                    while(head+end <= expr1.size()){
                        if(expr1.substr(head+end,1).compare(" ")!=0 && (head+end)<expr1.size())
                           end++;
                        else{
                           tempToken = expr1.substr(head,end);
                           head = head + end + 1;
                           end = 0;
                           count++;
                        }
                        if(count == 1)
                          expr1Op = tempToken;
                        if(count == 2)
                          expr1Id = tempToken;
                    }
                    for(int l=0;l<symbolTable.size();l++){
                       if(exprId.compare(symbolTable[l].getSymbol())==0)
                          type1 = symbolTable[l].getType();
                    }
                    for(int l=0;l<symbolTable.size();l++){
                       if(expr1Id.compare(symbolTable[l].getSymbol())==0)
                          type2 = symbolTable[l].getType();
                    }
                    if(type2.compare("int")==0){ //id is int
                       fileOut2 << "%" << itos(tempRegNum) << " = load i32* %" << expr1Id << ", align 4" << endl;
                       expr1IdRegNum = tempRegNum;
                       tempRegNum++;
                    }
                    if(type2.compare("double")==0){ //id is double
                       fileOut2 << "%" << itos(tempRegNum) << " = load double* %" << expr1Id << ", align 8" << endl;
                       expr1IdRegNum = tempRegNum;
                       tempRegNum++;
                    }
                    if(type1.compare(type2)==0){
                       fileOut2 << "%" << itos(tempRegNum) << " = ";
                       tempRegNum++;
                       if(type1.compare("int")==0){
                          if(expr1Op.compare("+")==0)
                             fileOut2 << "add nsw i32 ";
                          if(expr1Op.compare("-")==0)
                             fileOut2 << "sub nsw i32 ";
                          if(expr1Op.compare("*")==0)
                             fileOut2 << "mul nsw i32 ";
                          if(expr1Op.compare("/")==0)
                             fileOut2 << "sdiv i32 ";
                          /*if(op.compare(">")==0)
                             cout << "icmp sgt i32 ";
                          if(op.compare("<")==0)
                             cout << "icmp slt i32 ";*/
                       }else{
                          if(expr1Op.compare("+")==0)
                             fileOut2 << "fadd double ";
                          if(expr1Op.compare("-")==0)
                             fileOut2 << "fsub double ";
                          if(expr1Op.compare("*")==0)
                             fileOut2 << "fmul double ";
                          if(expr1Op.compare("/")==0)
                             fileOut2 << "fdiv double ";
                          /*if(op.compare(">")==0)
                             cout << "icmp sgt double ";
                          if(op.compare("<")==0)
                             cout << "icmp slt double ";*/
                       }
                       fileOut2 << "%" << exprReg << ", %" << expr1IdRegNum << endl;
                       return itos(tempRegNum-1)+" "+exprId;
                    }
                    if(type1.compare("double")==0 && type2.compare("int")==0){
                       fileOut2 << "%" << itos(tempRegNum) << " = sitofp i32 %" << itos(tempRegNum-1)  << " to double" << endl;
                       tempRegNum++;
                       // handle  %num = op type num-2 num-1
                       fileOut2 << "%" << itos(tempRegNum) << " = ";
                       tempRegNum++;
                       if(expr1Op.compare("+")==0)
                          fileOut2 << "fadd double ";
                       if(expr1Op.compare("-")==0)
                          fileOut2 << "fsub double ";
                       if(expr1Op.compare("*")==0)
                          fileOut2 << "fmul double ";
                       if(expr1Op.compare("/")==0)
                          fileOut2 << "fdiv double ";
                       fileOut2 << "%" << exprReg << ", %" << expr1IdRegNum << endl;
                       return itos(tempRegNum-1)+" "+exprId;
                    }
                    if(type1.compare("int")==0 && type2.compare("double")==0){
                       fileOut2 << "%" << itos(tempRegNum) << " = sitofp i32 %" << exprReg << " to double" << endl;
                       tempRegNum++;
                       // handle  %num = op type num-2 num-1
                       fileOut2 << "%" << itos(tempRegNum) << " = ";
                       tempRegNum++;
                       if(expr1Op.compare("+")==0)
                          fileOut2 << "fadd double ";
                       if(expr1Op.compare("-")==0)
                          fileOut2 << "fsub double ";
                       if(expr1Op.compare("*")==0)
                          fileOut2 << "fmul double ";
                       if(expr1Op.compare("/")==0)
                          fileOut2 << "fdiv double ";
                       fileOut2 << "%" << itos(tempRegNum-2) << ", %" << expr1IdRegNum << endl;
                       return itos(tempRegNum-1)+" "+expr1Id;

                    }

                 }
              }
///
          }//End of case:
          if(tree[i].getTreeNode().compare("id")==0){ //Expr->id ExprIdTail
              string id = "null", expridtail = "null";
              id = Id(i+1,tree[i].getTreeLevel());
              // handle second part: find Expr'
              for(int j=i+1;j<tree.size();j++){
                 if(tree[j].getTreeLevel()==treeLevel+1){
                    if(tree[j].getTreeNode().compare("ExprIdTail")==0){
                        expridtail = ExprIdTail(j+1,tree[j].getTreeLevel(),id);
                        j = tree.size(); //break loop
                    }
                 }
              }
              if(id.compare("null")!=0 && expridtail.compare("null")!=0 && expridtail.compare("epsilon")!=0){ //expridtail is a register number
                 //this case need to split string, expridtail = BinOp+" "+Expr(id)
                 int tokenCase = 1;
                 string tempToken;
                 string op = "null", token = "null", regNum = "null";
                 int head=0, end=0, count = 0;
                 while(head+end <= expridtail.size()){
                     if(expridtail.substr(head+end,1).compare(" ")!=0 && (head+end)<expridtail.size())
                         end++;
                     else{
                         tempToken = expridtail.substr(head,end);
                         //token = expridtail.substr(end+1,expridtail.size()-end-1);
                         head = head + end + 1;
                         end = 0;
                         count++;
                     }
                     if(count == 1)
                        op = tempToken;
                     if(count == 2)
                        token = tempToken;
                     if(count == 3)
                        regNum = tempToken;
                 }
                 //check case : 1.one token 2.two tokens 3.three tokens
                 if(token.compare("null")==0 && regNum.compare("null")==0)
                    tokenCase = 1;
                 else if(token.compare("null")!=0 && regNum.compare("null")==0){
                    if(numDFASym(op).compare("false")==0)
                       tokenCase = 2;
                    else
                       tokenCase = 4;
                 }
                 else
                    tokenCase = 3;
                 //handle each case
                 if(tokenCase == 1){
                    //Need to check expridtail is number or register number
                    string check = "%";
                    if(expridtail[0] == check[0]){ //array operation case
                       // return register number witout % and id
                       return expridtail.substr(1,expridtail.size()-1)+" "+id;
                    }else{ //identifer assign value
                       string type = "null";
                       for(int o=0;o<symbolTable.size();o++){
                          if(id.compare(symbolTable[o].getSymbol())==0)
                              type = symbolTable[o].getType();
                       }
                       fileOut2 << "store ";
                       if(type.compare("int")==0){
                          if(numDFASym(expridtail).compare("double")==0){
                             string intStr = "null";
                             int head = 0, end = 0;
                             while(head+end <= expridtail.size()){
                                if(expridtail.substr(head+end,1).compare(".")!=0 && (head+end)<expridtail.size())
                                   end++;
                                else{
                                   intStr = expridtail.substr(head,end);
                                   end = expridtail.size()+1;
                                }
                             }
                             fileOut2 << "i32 " << intStr << ", i32* %" << id << ", align 4" << endl;
                          }
                          else 
                             fileOut2 << "i32 " << expridtail << ", i32* %" << id << ", align 4" << endl;
                       }
                       if(type.compare("double")==0){
                          if(numDFASym(expridtail).compare("int")==0){
                             string douStr = expridtail+".0";
                             fileOut2 << "double " << douStr << ",double* %" << id << ", align 8" << endl;
                          }
                          else
                             fileOut2 << "double " << expridtail << ",double* %" << id << ", align 8" << endl;
                       }
                       return "null";
                    }
                 }
                 //End of one token case
                 if(tokenCase == 2){ //Case: expridtail = BinOp+" "+Expr(token)
                  if(numDFASym(token).compare("false")!=0){
////
                     string type1, type2;
                     for(int w=0;w<symbolTable.size();w++){
                        if(id.compare(symbolTable[w].getSymbol())==0){
                           type1 = symbolTable[w].getType();
                        }
                     }
                     type2 = numDFASym(token);
                     if(type1.compare(type2)==0){
                        fileOut2 << "%" << itos(tempRegNum) << " = load ";
                        tempRegNum++;
                        if(type1.compare("int")==0)
                           fileOut2 << "i32* %" << id << ", align 4" << endl;
                        else
                           fileOut2 << "double* %" << id << ", align 8" << endl;
                        // handle  %num = op type num-2 num-1
                        fileOut2 << "%" << itos(tempRegNum) << " = ";
                        tempRegNum++;
                        if(type1.compare("int")==0){
                          if(op.compare("+")==0)
                             fileOut2 << "add nsw i32 ";
                          if(op.compare("-")==0)
                             fileOut2 << "sub nsw i32 ";
                          if(op.compare("*")==0)
                             fileOut2 << "mul nsw i32 ";
                          if(op.compare("/")==0)
                             fileOut2 << "sdiv i32 ";
                          /*if(op.compare(">")==0)
                             cout << "icmp sgt i32 ";
                          if(op.compare("<")==0)
                             cout << "icmp slt i32 ";*/
                        }else{
                          if(op.compare("+")==0)
                             fileOut2 << "fadd double ";
                          if(op.compare("-")==0)
                             fileOut2 << "fsub double ";
                          if(op.compare("*")==0)
                             fileOut2 << "fmul double ";
                          if(op.compare("/")==0)
                             fileOut2 << "fdiv double ";
                          /*if(op.compare(">")==0)
                             cout << "icmp sgt double ";
                          if(op.compare("<")==0)
                             cout << "icmp slt double ";*/
                        }
                        fileOut2 << "%" << itos(tempRegNum-2) << ", " << token << endl;
                        return itos(tempRegNum-1)+" "+id;
                     }
                     if(type1.compare("int")==0 && type2.compare("double")==0){
                        fileOut2 << "%" << itos(tempRegNum) << " = load i32* %" << id << ", align 4" << endl;
                        tempRegNum++;
                        fileOut2 << "%" << itos(tempRegNum) << " = sitofp i32 %" << itos(tempRegNum-1) << " to double" << endl;
                        tempRegNum++;
                        // handle  %num = op type num-2 num-1
                        fileOut2 << "%" << itos(tempRegNum) << " = ";
                        tempRegNum++;
                        if(op.compare("+")==0)
                           fileOut2 << "fadd double ";
                        if(op.compare("-")==0)
                           fileOut2 << "fsub double ";
                        if(op.compare("*")==0)
                           fileOut2 << "fmul double ";
                        if(op.compare("/")==0)
                           fileOut2 << "fdiv double ";
                        fileOut2 << "%" << itos(tempRegNum-2) << ", " << token << endl;
                        string douId;
                        for(int x=0;x<symbolTable.size();x++){
                           if(symbolTable[x].getType().compare("double")==0)
                              douId = symbolTable[x].getSymbol();
                        }
                        return itos(tempRegNum-1)+" "+douId;
                     }
                     if(type1.compare("double")==0 && type2.compare("int")==0){
                        fileOut2 << "%" << itos(tempRegNum) << " = load double* %" << id << ", align 8" << endl;
                        tempRegNum++;
                        string douStr = token+".0";
                        fileOut2 << "%" << itos(tempRegNum) << " = ";
                        tempRegNum++;
                        if(op.compare("+")==0)
                           fileOut2 << "fadd double ";
                        if(op.compare("-")==0)
                           fileOut2 << "fsub double ";
                        if(op.compare("*")==0)
                           fileOut2 << "fmul double ";
                        if(op.compare("/")==0)
                           fileOut2 << "fdiv double ";
                        fileOut2 << "%" << itos(tempRegNum-2) << ", " << douStr << endl;
                        return itos(tempRegNum-1)+" "+id;
                     }
                  }else{
                    int typeConNum = 0; //need to convert type token number
                    string type1 , type2;
                    for(int w=0;w<symbolTable.size();w++){
                       if(id.compare(symbolTable[w].getSymbol())==0){
                          type1 = symbolTable[w].getType();
                       }
                    }
                    for(int w=0;w<symbolTable.size();w++){
                       if(token.compare(symbolTable[w].getSymbol())==0){
                          type2 = symbolTable[w].getType();
                       }
                    }
                    if(type1.compare(type2)!=0){ // have different type need to convert int tp double
                       if(type1.compare("int")==0)
                          typeConNum = 1;
                       if(type2.compare("int")==0)
                          typeConNum = 2;                      
                    }
                    if(typeConNum==0){
                       //first one
                       fileOut2 << "%" << itos(tempRegNum) << " = load ";
                       tempRegNum++;
                       if(type1.compare("int")==0)
                          fileOut2 << "i32* %" << id << ", align 4" << endl;
                       else
                          fileOut2 << "double* %" << id << ", align 8" << endl;
                       //second one
                       fileOut2 << "%" << itos(tempRegNum) << " = load ";
                       tempRegNum++;
                       if(type2.compare("int")==0)
                          fileOut2 << "i32* %" << token << ", align 4" << endl;
                       else
                          fileOut2 << "double* %" << token << ", align 8" << endl;
                       // handle  %num = op type num-2 num-1
                       fileOut2 << "%" << itos(tempRegNum) << " = ";
                       tempRegNum++;
                       if(type1.compare("int")==0){
                          if(op.compare("+")==0)
                             fileOut2 << "add nsw i32 ";
                          if(op.compare("-")==0)
                             fileOut2 << "sub nsw i32 ";
                          if(op.compare("*")==0)
                             fileOut2 << "mul nsw i32 ";
                          if(op.compare("/")==0)
                             fileOut2 << "sdiv i32 ";
                          /*if(op.compare(">")==0)
                             cout << "icmp sgt i32 ";
                          if(op.compare("<")==0)
                             cout << "icmp slt i32 ";*/
                       }else{
                          if(op.compare("+")==0)
                             fileOut2 << "fadd double ";
                          if(op.compare("-")==0)
                             fileOut2 << "fsub double ";
                          if(op.compare("*")==0)
                             fileOut2 << "fmul double ";
                          if(op.compare("/")==0)
                             fileOut2 << "fdiv double ";
                          /*if(op.compare(">")==0)
                             cout << "icmp sgt double ";
                          if(op.compare("<")==0)
                             cout << "icmp slt double ";*/
                       }
                       fileOut2 << "%" << itos(tempRegNum-3) << ", %" << itos(tempRegNum-2) << endl;
                       return itos(tempRegNum-1)+" "+id;
                    }
                    else if(typeConNum==1){
                       // first one => id (which is int)
                       fileOut2 << "%" << itos(tempRegNum) << " = load i32* %" << id << ", align 4" << endl;
                       tempRegNum++;
                       fileOut2 << "%" << itos(tempRegNum) << " = sitofp i32 %" << itos(tempRegNum-1) << " to double" << endl;
                       tempRegNum++;
                       // second one => token (which is double)
                       fileOut2 << "%" << itos(tempRegNum) << " = load double* %" << token << ", align 8" << endl;
                       tempRegNum++;
                       // handle  %num = op type num-2 num-1
                       fileOut2 << "%" << itos(tempRegNum) << " = ";
                       tempRegNum++;
                       if(op.compare("+")==0)
                          fileOut2 << "fadd double ";
                       if(op.compare("-")==0)
                          fileOut2 << "fsub double ";
                       if(op.compare("*")==0)
                          fileOut2 << "fmul double ";
                       if(op.compare("/")==0)
                          fileOut2 << "fdiv double ";
                       fileOut2 << "%" << itos(tempRegNum-3) << ", %" << itos(tempRegNum-2) << endl;
// because token is double and id is int so return token to stand for type
                       return itos(tempRegNum-1)+" "+token; 
                    }else{
                       // first one => id (which is double)
                       fileOut2 << "%" << itos(tempRegNum) << " = load double* %" << id << ", align 8" << endl;
                       tempRegNum++;
                       // second one => token (which is int)
                       fileOut2 << "%" << itos(tempRegNum) << " = load i32* %" << token << ", align 4" << endl;
                       tempRegNum++;
                       fileOut2 << "%" << itos(tempRegNum) << " = sitofp i32 %" << itos(tempRegNum-1) << " to double" << endl;
                       tempRegNum++;
                       // handle  %num = op type num-2 num-1
                       fileOut2 << "%" << itos(tempRegNum) << " = ";
                       tempRegNum++;
                       if(op.compare("+")==0)
                          fileOut2 << "fadd double ";
                       if(op.compare("-")==0)
                          fileOut2 << "fsub double ";
                       if(op.compare("*")==0)
                          fileOut2 << "fmul double ";
                       if(op.compare("/")==0)
                          fileOut2 << "fdiv double ";
                       fileOut2 << "%" << itos(tempRegNum-4) << ", %" << itos(tempRegNum-2) << endl;
                       return itos(tempRegNum-1)+" "+id;
                    }
                  }
                 }
                 if(tokenCase == 3){  // two case
                    if(op.compare("=")==0){
                    //Case: op => = , token => number, regNum => register number
                       string idType;
                       for(int k=0;k<symbolTable.size();k++){
                           if(id.compare(symbolTable[k].getSymbol())==0)
                              idType = symbolTable[k].getType();
                       }
                       if(idType.compare("int")==0){ //id is int
                          if(numDFASym(token).compare("int")==0){  //token is int
                             fileOut2 << "store i32 " << token << ", i32* %" << regNum << ", align 4" <<endl;
                          }
                          if(numDFASym(token).compare("double")==0){ //token is double
                             string intToken;
                             int head=0, end=0;
                             while(head+end <= token.size()){
                                if(token.substr(head+end,1).compare(".")!=0)
                                   end++;
                                else{
                                   intToken = token.substr(head,end);
                                   end = token.size()+1;
                                }
                             }
                             fileOut2 << "store i32 " << intToken << ", i32* %" << regNum << ", align 4" <<endl;
                          }
                       }//end of id is int case
                       if(idType.compare("double")==0){ //id is double
                          if(numDFASym(token).compare("int")==0){  //token is int
                             fileOut2 << "store double " << token << ".0, double* %" << regNum << ", align 8" <<endl;
                          }
                          if(numDFASym(token).compare("double")==0){ //token is double
                             fileOut2 << "store double " << token << ", double* %" << regNum << ", align 8" <<endl;
                          }
                       }//end of id is double case
                    }else{  // op is not '=' that is case => op+" "+regNum+" "+id 
                        // op - op , token - regNum , regNum - id
                        string type1 , type2;
                        int lastTimeRegNum;
//
                        cout << "2194 , id = " << id << ", regNum(old id) = " << regNum<< endl;
                        for(int t=0;t<symbolTable.size();t++){
                           if(id.compare(symbolTable[t].getSymbol())==0)
                               type1 = symbolTable[t].getType();
                        }
                        for(int t=0;t<symbolTable.size();t++){
                           if(regNum.compare(symbolTable[t].getSymbol())==0)
                               type2 = symbolTable[t].getType();
                        }
                        if(type1.compare("int")==0){ //id is int
                           fileOut2 << "%" << itos(tempRegNum) << " = load i32* %" << id << ", align 4" << endl;
                           lastTimeRegNum = tempRegNum;
                           tempRegNum++;
                        }  
                        if(type1.compare("double")==0){ //id is double
                           fileOut2 << "%" << itos(tempRegNum) << " = load double* %" << id << ", align 8" << endl;
                           lastTimeRegNum = tempRegNum;
                           tempRegNum++;
                        }
                        if(type1.compare(type2)==0){ //same type
                            if(type1.compare("int")==0){
                               fileOut2 << "%" << itos(tempRegNum) << " = ";
                               if(op.compare("+")==0)
                                  fileOut2 << "add nsw i32 ";
                               if(op.compare("-")==0)
                                  fileOut2 << "sub nsw i32 ";
                               if(op.compare("*")==0)
                                  fileOut2 << "mul nsw i32 ";
                               if(op.compare("/")==0)
                                  fileOut2 << "sdiv i32 ";
                               fileOut2 << "%" << lastTimeRegNum << ", %" << token << endl;
                            }
                            if(type1.compare("double")==0){
                               fileOut2 << "%" << itos(tempRegNum) << " = ";
                               if(op.compare("+")==0)
                                  fileOut2 << "fadd double ";
                               if(op.compare("-")==0)
                                  fileOut2 << "fsub double ";
                               if(op.compare("*")==0)
                                  fileOut2 << "fmul double ";
                               if(op.compare("/")==0)
                                  fileOut2 << "fdiv double ";
                               fileOut2 << "%" << lastTimeRegNum << ", %" << token << endl;
                            }
                            tempRegNum++;
                            return itos(tempRegNum-1)+" "+id;
                        }
                        if(type1.compare("int")==0 && type2.compare("double")==0){
                            fileOut2 << "%" << itos(tempRegNum) << " =  sitofp i32 %" << lastTimeRegNum << " to double" << endl;
                            lastTimeRegNum = tempRegNum; //update register number which store int
                            tempRegNum++;
                            fileOut2 << "%" << itos(tempRegNum) << " = ";
                            if(op.compare("+")==0)
                               fileOut2 << "fadd double ";
                            if(op.compare("-")==0)
                               fileOut2 << "fsub double ";
                            if(op.compare("*")==0)
                               fileOut2 << "fmul double ";
                            if(op.compare("/")==0)
                               fileOut2 << "fdiv double ";
                            fileOut2 << "%" << lastTimeRegNum << ", %" << token << endl;
                            tempRegNum++;
                            return itos(tempRegNum-1)+" "+regNum;  //regNum is old id
                        }
                        if(type1.compare("double")==0 && type2.compare("int")==0){
                            fileOut2 << "%" << itos(tempRegNum) << " =  sitofp i32 %" << token << " to double" << endl;
                            regNum = itos(tempRegNum); //update register number which store id
                            tempRegNum++;
                            fileOut2 << "%" << itos(tempRegNum) << " = ";
                            if(op.compare("+")==0)
                               fileOut2 << "fadd double ";
                            if(op.compare("-")==0)
                               fileOut2 << "fsub double ";
                            if(op.compare("*")==0)
                               fileOut2 << "fmul double ";
                            if(op.compare("/")==0)
                               fileOut2 << "fdiv double ";
                            fileOut2 << "%" << lastTimeRegNum << ", %" << token << endl;
                            tempRegNum++;
                            return itos(tempRegNum-1)+" "+id;
                        }
//
                    } 
                 }
                 if(tokenCase == 4){  //expridtail = regNum+" "+id
                    return expridtail;
                 }
              }
              else if(id.compare("null")!=0 && expridtail.compare("null")!=0){  // expridtail == epsilon
                 //Case : right most one in formula 
                 return id;
              }
          i = tree.size();
          }
          //End of case
      }
   }
   return "null";
}
  
//still have problem
string ExprIdTail(int index,int treeLevel,string id){
    for(int i=index;i<tree.size();i++){
        if(tree[i].getTreeLevel() == treeLevel+1){
             if(tree[i].getTreeNode().compare("Expr'")==0){
                 string expr1;
                 expr1 = Expr1(i+1,tree[i].getTreeLevel());
                 return expr1;
             }
             //Case : ExprIdTail -> ( ExprList ) Expr'
// call function need it
             if(tree[i].getTreeNode().compare("(")==0){ //call function case
                 string exprlist;
                 string expr1;
                 exprlist = ExprList(i+2,tree[i+1].getTreeLevel()); 
                 //exprlist => id+" "+id+" "+id+...
                 int head=0, end=0;
                 vector<string> tempId;
                 while(head+end <= exprlist.size()){
                     if(exprlist.substr(head+end,1).compare(" ")!=0 && (head+end)<exprlist.size())
                        end++;
                     else{
                        if(exprlist.substr(head,end).compare("epsilon")!=0)
                           tempId.push_back(exprlist.substr(head,end));
                        head = head + end + 1;
                        end = 0;
                     }
                 }
                 for(int l=0;l<tempId.size();l++){
                    fileOut2 <<"%"<<itos(tempRegNum)<<" = ";
                    for(int m=0;m<symbolTable.size();m++){
                       if(tempId[l].compare(symbolTable[m].getSymbol())==0){
                          if(symbolTable[m].getArray()==0){
                             if(symbolTable[m].getType().compare("int")==0)
                                fileOut2 << "load i32* %" << symbolTable[m].getSymbol() << ", align 4" << endl;
                             else
                                fileOut2 << "load double* %" << symbolTable[m].getSymbol() << ", align 8" << endl;
                          }else{ 
                             if(symbolTable[m].getType().compare("int")==0)
                                fileOut2<<"getelementptr inbounds ["<<symbolTable[m].getArraySize() <<" x i32]* %"<<symbolTable[m].getSymbol() << ", i32 0, i32 0" << endl;
                             else
                                fileOut2<<"getelementptr inbounds ["<<symbolTable[m].getArraySize() <<" x double]* %"<<symbolTable[m].getSymbol()<<",i32 0,i32 0" << endl;
                       
                          }
                          //symbolTable[m].setParam(tempRegNum);
                       }
                    }
                    tempRegNum++;
                 }
                 fileOut2 <<"%"<<itos(tempRegNum)<<" = call ";
                 for(int r=0;r<symbolTable.size();r++){
                    if(id.compare(symbolTable[r].getSymbol())==0){
                       if(symbolTable[r].getType().compare("int")==0)
                          fileOut2 << "i32 @" << id << "(";
                       if(symbolTable[r].getType().compare("double")==0)
                          fileOut2 << "double @" << id << "(";
                    }
                 }
                 int count = 0;
                 while(count<tempId.size()){
                 for(int r=0;r<symbolTable.size();r++){
                    if(tempId[count].compare(symbolTable[r].getSymbol())==0){
                       if(symbolTable[r].getType().compare("int")==0){
                          if(symbolTable[r].getArray()==0)
                             fileOut2 << "i32 %" << itos(tempRegNum-tempId.size()+count);
                          else
                             fileOut2 << "i32* %" << itos(tempRegNum-tempId.size()+count);
                       }
                       if(symbolTable[r].getType().compare("double")==0){
                          if(symbolTable[r].getArray()==0)
                             fileOut2 << "double %" << itos(tempRegNum-tempId.size()+count);
                          else
                             fileOut2 << "double* %" << itos(tempRegNum-tempId.size()+count);
                       }
                    }  
                 }
                 if(count<tempId.size()-1)
                   fileOut2 <<", ";
                 count++;
                 }
                 fileOut2 <<")"<<endl;
                 tempRegNum++;
                 for(int j=i+2;j<tree.size();j++){
                    if(tree[j].getTreeLevel() == treeLevel+1){
                       if(tree[j].getTreeNode().compare("Expr'")==0){
                          expr1 = Expr1(j+1,tree[j].getTreeLevel());
                          j = tree.size(); // break loop
                       }
                    }
                 }
// return value
// have problem
             }
             //Case : ExprIdTail -> [ Expr ] ExprArrayTail
             if(tree[i].getTreeNode().compare("[")==0){
                // i+1 -> Expr location
                string expr;
                int index;
                int origionRegNum;
                int lastTimeRegNum;
                expr = Expr(i+2,tree[i+1].getTreeLevel()); //maybe get a number
// Need :test is number or not ? don't need?
                for(int k=0;k<symbolTable.size();k++){
                    if(id.compare(symbolTable[k].getSymbol())==0){
                       index = k;
                       k = symbolTable.size(); //break loop
                    }
                }
                if(symbolTable[index].getType().compare("int")==0){
                   fileOut2 << "%" << itos(tempRegNum) << " = getelementptr inbounds [" << symbolTable[index].getArraySize() <<" x i32]";
                   fileOut2 << "* %" << id << ", i32 0, i64 " << expr << endl;
                   origionRegNum = tempRegNum;
                   tempRegNum++;
                }
                if(symbolTable[index].getType().compare("double")==0){
                   fileOut2 << "%" << itos(tempRegNum) << " = getelementptr inbounds [" << symbolTable[index].getArraySize() <<" x double]";
                   fileOut2 << "* %" << id << ", i32 0, i64 " << expr << endl;
                   origionRegNum = tempRegNum;
                   tempRegNum++;
                }
                for(int j=i+2;j<tree.size();j++){
                   if(tree[j].getTreeLevel() == treeLevel+1){
                      if(tree[j].getTreeNode().compare("ExprArrayTail")==0){
                         //Case : ExprArrayTail -> Expr' is array operation
                         if(tree[j+1].getTreeNode().compare("Expr'")==0){
                            if(symbolTable[index].getType().compare("int")==0){ //id is int
                               fileOut2 << "%" << itos(tempRegNum) << " = load i32* %" << itos(tempRegNum-1) << ", align 4" << endl;
                               lastTimeRegNum = tempRegNum;
                               tempRegNum++;
                            }
                            if(symbolTable[index].getType().compare("double")==0){ //id is double
                               fileOut2 << "%" << itos(tempRegNum) << " = load double* %" << itos(tempRegNum-1) << ", align 8" << endl;
                               lastTimeRegNum = tempRegNum;
                               tempRegNum++;
                            }
                         }
                         string exprarraytail;
                         exprarraytail = ExprArrayTail(j+1,tree[j].getTreeLevel());
                         int tokenCase = 0;
                         int head=0, end=0, count = 0;
                         string tempToken;
                         string op = "null", regNum = "null" , anoId = "null";
                         while(head+end <= exprarraytail.size()){
                            if(exprarraytail.substr(head+end,1).compare(" ")!=0 && (head+end)<exprarraytail.size())
                               end++;
                            else{
                               tempToken = exprarraytail.substr(head,end);
                               head = head + end + 1;
                               end = 0;
                               count++;
                            }
                            if(count == 1)
                               op = tempToken;
                            if(count == 2)
                               regNum = tempToken;
                            if(count == 3)
                               anoId = tempToken;
                         }
                         //check case : 1.one token 2.two tokens 3.three tokens
                         if(regNum.compare("null")==0 && anoId.compare("null")==0)
                            tokenCase = 1;
                         else if(regNum.compare("null")!=0 && anoId.compare("null")==0)
                            tokenCase = 2;
                         else if(op.compare("=")==0 && regNum.compare("null")!=0 && anoId.compare("null")!=0)
                            tokenCase = 3;
                         else
                            tokenCase = 4;
                         //set return value
                         if(tokenCase == 1 /*exprarraytail.compare("epsilon")==0*/)
                            return "%"+itos(tempRegNum-1);
                         else if(tokenCase == 2) //exprarraytail = "= " + id , so return binop+" "+num+regNum
                            return exprarraytail+" "+itos(tempRegNum-1);
                         else if(tokenCase == 3){
                            string type1 , type2;
                            for(int m=0;m<symbolTable.size();m++){
                               if(id.compare(symbolTable[m].getSymbol())==0)
                                  type1 = symbolTable[m].getType();
                            }
                            for(int m=0;m<symbolTable.size();m++){
                               if(anoId.compare(symbolTable[m].getSymbol())==0)
                                  type2 = symbolTable[m].getType();
                            }
                            if(type1.compare(type2)==0){
                                if(type1.compare("int")==0)
                                   fileOut2 << "store i32 %" << regNum << ", i32* %" << origionRegNum << ", align 4" << endl;
                                if(type2.compare("double")==0)
                                   fileOut2 << "store double %" << regNum << ", double* %" << origionRegNum << ", align 8" << endl;
                            }
                            else{
                                if(type1.compare("double")==0 && type2.compare("int")==0){
                                   fileOut2 << "%" << itos(tempRegNum) << " = sitofp i32 %" << regNum << " to double" << endl;
                                   fileOut2 << "store double %" << tempRegNum << ", double* %" << origionRegNum << ", align 8" << endl;
                                   tempRegNum++;
                                }
                                if(type1.compare("int")==0 && type2.compare("double")==0){
                                   fileOut2 << "%" << itos(tempRegNum) << " = fptosi double %" << regNum << " to i32" << endl;
                                   fileOut2 << "store i32 %" << tempRegNum << ", i32* %" << origionRegNum << ", align 4" << endl; 
                                   tempRegNum++;                    
                                }
                            }
                            return "epsilon";
                         }
                         else{ //exprarraytail = BinOP+" "+regNum+" "+id
/////////
                            string type1 , type2;
                            for(int m=0;m<symbolTable.size();m++){
                               if(id.compare(symbolTable[m].getSymbol())==0)
                                  type1 = symbolTable[m].getType();
                            }
                            for(int m=0;m<symbolTable.size();m++){
                               if(anoId.compare(symbolTable[m].getSymbol())==0)
                                  type2 = symbolTable[m].getType();
                            }
                            //check type is same or not
                            if(type1.compare(type2)==0){ //same type
                               if(type1.compare("int")==0){
                                  fileOut2 << "%" << itos(tempRegNum) << " = ";
                                  if(op.compare("+")==0)
                                     fileOut2 << "add nsw i32 ";
                                  if(op.compare("-")==0)
                                     fileOut2 << "sub nsw i32 ";
                                  if(op.compare("*")==0)
                                     fileOut2 << "mul nsw i32 ";
                                  if(op.compare("/")==0)
                                     fileOut2 << "sdiv i32 ";
                                  fileOut2 << "%" << lastTimeRegNum << ", %" << regNum << endl;
                               }
                               if(type1.compare("double")==0){
                                  cout << "%" << itos(tempRegNum) << " = ";
                                  if(op.compare("+")==0)
                                     fileOut2 << "fadd double ";
                                  if(op.compare("-")==0)
                                     fileOut2 << "fsub double ";
                                  if(op.compare("*")==0)
                                     fileOut2 << "fmul double ";
                                  if(op.compare("/")==0)
                                     fileOut2 << "fdiv double ";
                                  fileOut2 << "%" << lastTimeRegNum << ", %" << regNum << endl;
                               }
                               tempRegNum++;
                               return itos(tempRegNum-1)+" "+id;
                            }
                            if(type1.compare("int")==0 && type2.compare("double")==0){
                                  fileOut2 << "%" << itos(tempRegNum) << " =  sitofp i32 %" << lastTimeRegNum << " to double" << endl;
                                  lastTimeRegNum = tempRegNum; //update register number which store int
                                  tempRegNum++;
                                  fileOut2 << "%" << itos(tempRegNum) << " = ";
                                  if(op.compare("+")==0)
                                     fileOut2 << "fadd double ";
                                  if(op.compare("-")==0)
                                     fileOut2 << "fsub double ";
                                  if(op.compare("*")==0)
                                     fileOut2 << "fmul double ";
                                  if(op.compare("/")==0)
                                     fileOut2 << "fdiv double ";
                                  fileOut2 << "%" << lastTimeRegNum << ", %" << regNum << endl;
                                  tempRegNum++;
                                  return itos(tempRegNum-1)+" "+anoId;
                            }
                            if(type1.compare("double")==0 && type2.compare("int")==0){
                                  fileOut2 << "%" << itos(tempRegNum) << " =  sitofp i32 %" << regNum << " to double" << endl;
                                  regNum = itos(tempRegNum); //update register number which store id
                                  tempRegNum++;
                                  fileOut2 << "%" << itos(tempRegNum) << " = ";
                                  if(op.compare("+")==0)
                                     fileOut2 << "fadd double ";
                                  if(op.compare("-")==0)
                                     fileOut2 << "fsub double ";
                                  if(op.compare("*")==0)
                                     fileOut2 << "fmul double ";
                                  if(op.compare("/")==0)
                                     fileOut2 << "fdiv double ";
                                  fileOut2 << "%" << lastTimeRegNum << ", %" << regNum << endl;
                                  tempRegNum++;
                                  return itos(tempRegNum-1)+" "+id;
                            }
                         }//End of case
                      j = tree.size();
                      }
                   }
                }
             }
             //Case : ExprIdTail -> = Expr
             if(tree[i].getTreeNode().compare("=")==0){
                 for(int j=i+1;j<tree.size();j++){
                     if(tree[j].getTreeLevel() == treeLevel+1){
                         if(tree[j].getTreeNode().compare("Expr")==0){
                            string expr;
                            expr = Expr(j+1,tree[j].getTreeLevel());
                            int idIndex;
                            int exprCase = 0;
                            int head1=0, end1=0, count1 = 0;
                            string regNum1 = "null", id1 = "null" ,tempT = "null";
                            string type1, type2;
                            while(head1+end1 <= expr.size()){
                                if(expr.substr(head1+end1,1).compare(" ")!=0 && (head1+end1)<expr.size())
                                   end1++;
                                else{
                                   tempT = expr.substr(head1,end1);
                                   head1 = head1 + end1 + 1;
                                   end1 = 0;
                                   count1++;
                                }
                                if(count1 == 1)
                                   regNum1 = tempT;
                                if(count1 == 2)
                                   id1 = tempT;
                            }
                            if(regNum1.compare("null")!=0 && id1.compare("null")!=0)
                               exprCase = 1;
                            else  exprCase = 2;
                            if(exprCase == 1){ // expr is : regNum+" "+id
                               for(int a=0;a<symbolTable.size();a++){
                                   if(id.compare(symbolTable[a].getSymbol())==0){
                                     idIndex = a;
                                     type1 = symbolTable[a].getType();
                                   }
                               }
                               for(int a=0;a<symbolTable.size();a++){
                                  if(id1.compare(symbolTable[a].getSymbol())==0){
                                     type2 = symbolTable[a].getType();
                                  }
                               }
                               // type checking
                               if(type1.compare(type2)==0){
                                  if(type1.compare("int")==0){
                                     if(symbolTable[idIndex].getScope()==0) //global variable
                                        fileOut2 << "store i32 %" << regNum1 << ", i32* @" << id << ", align 4" << endl;
                                     else
                                        fileOut2 << "store i32 %" << regNum1 << ", i32* %" << id << ", align 4" << endl;
                                  }
                                  if(type2.compare("double")==0){
                                     if(symbolTable[idIndex].getScope()==0) //global variable
                                        fileOut2 << "store double %" << regNum1 << ", double* @" << id << ", align 8" << endl;    
                                     else
                                        fileOut2 << "store double %" << regNum1 << ", double* %" << id << ", align 8" << endl;
                                  }
                               }
                               if(type1.compare("int")==0 && type2.compare("double")==0){
                                  fileOut2 << "%" << itos(tempRegNum) << " = fptosi double %" << regNum1 << " to i32" << endl;
                                  if(symbolTable[idIndex].getScope()==0) //global variable
                                     fileOut2 << "store i32 %" << itos(tempRegNum) << ", i32* @" << id << ", align 4" << endl;
                                  else
                                     fileOut2 << "store i32 %" << itos(tempRegNum) << ", i32* %" << id << ", align 4" << endl;
                                  tempRegNum++;
                               }
                               if(type1.compare("double")==0 && type2.compare("int")==0){
                                  fileOut2 << "%" << itos(tempRegNum) << " = sitofp i32 %" << regNum1 << " to double" << endl;
                                  if(symbolTable[idIndex].getScope()==0) //global variable
                                     fileOut2 << "store double %" << itos(tempRegNum) << ", double* @" << id << ", align 8" << endl;
                                  else
                                     fileOut2 << "store double %" << itos(tempRegNum) << ", double* %" << id << ", align 8" << endl;
                                  tempRegNum++;
                               }
                            }
                            if(exprCase == 2){   // expr is number
// asign value ex: a = 5  and return register number case need to operate  => don't need to do it
                               return expr;
                            }
                            //break for loop
                            j = tree.size();  // don't need to return?
                         }
                     }
                 }
             }
             //end of case
             i = tree.size();
        }
    }
    return "null";
}
  
string ExprArrayTail(int index,int treeLevel){
   for(int i=index;i<tree.size();i++){
       if(tree[i].getTreeLevel() == treeLevel+1){
           //Case : ExprArrayTail -> Expr'
           if(tree[i].getTreeNode().compare("Expr'")==0){
              string expr1;
              expr1 = Expr1(i+1,tree[i].getTreeLevel());
              return expr1;
           }
           //Case : ExprArrayTail -> = Expr
           //Bug! Still have some problem
           if(tree[i].getTreeNode().compare("=")==0){
               for(int j=i+1;j<tree.size();j++){
                   if(tree[j].getTreeLevel() == treeLevel+1){
                       if(tree[j].getTreeNode().compare("Expr")==0){
                          string expr;
                          expr = Expr(j+1,tree[j].getTreeLevel());
                          return "= "+expr;
                          //break for loop
                          j = tree.size();
                       }
                   }
               }
           }
           //End of this case
       }
   }
   return "null";
}
  
string ExprList(int index,int treeLevel){
   for(int i=index;i<tree.size();i++){
       if(tree[i].getTreeLevel() == treeLevel+1){
           //Case : ExprList -> epsilon
           if(tree[i].getTreeNode().compare("epsilon")==0)
              return "epsilon";
           //Case : ExprList -> ExprListTail
           //Bug! Still have some problem
           if(tree[i].getTreeNode().compare("ExprListTail")==0){
              string exprlisttail;
              exprlisttail = ExprListTail(i+1,tree[i].getTreeLevel());
              return exprlisttail;
           }
       }
   }
   return "null";
}
  
// Not correct, still have problem
string ExprListTail(int index,int treeLevel){
   string expr = "null", exprlisttail1 = "null";
   for(int i=index;i<tree.size();i++){
       if(tree[i].getTreeLevel() == treeLevel+1){
           if(tree[i].getTreeNode().compare("Expr")==0){
              expr = Expr(i+1,tree[i].getTreeLevel());
           }
           if(tree[i].getTreeNode().compare("ExprListTail'")==0){
              exprlisttail1 = ExprListTail1(i+1,tree[i].getTreeLevel());
           }
       }
   }
   if(expr.compare("null")!=0 && exprlisttail1.compare("null")!=0)
     return expr+" "+exprlisttail1;
   else
     return "null";
}
  
// Not correct
string ExprListTail1(int index,int treeLevel){
   for(int i=index;i<tree.size();i++){
       if(tree[i].getTreeLevel() == treeLevel+1){
           //Case : ExprListTail' -> epsilon
           if(tree[i].getTreeNode().compare("epsilon")==0)
              return "epsilon";
           //Case : ExprListTail' -> , ExprListTail
           //Bug! Still have some problem
           if(tree[i].getTreeNode().compare("ExprListTail")==0){
              string exprlisttail;
              exprlisttail = ExprListTail(i+1,tree[i].getTreeLevel());
              return exprlisttail;
           }
       }
   }
   return "null";
}
