#include<iostream>
using namespace std;
char blank[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
void function1(){
  cout<<"    |    |    \n";
  cout<<"  "<<blank[0][0]<<" | "<<blank[0][1]<<"  | "<<blank[0][2]<<"   \n";
  cout<<"____|____|____\n";
  cout<<"    |    |    \n";
  cout<<"  "<<blank[1][0]<<" | "<<blank[1][1]<<"  | "<<blank[1][2]<<"   \n";
  cout<<"____|____|____\n";
  cout<<"    |    |    \n";
  cout<<"  "<<blank[2][0]<<" | "<<blank[2][1]<<"  | "<<blank[2][2]<<"   \n";
  cout<<"    |    |    \n";
}

int row,column;
char symbol = 'x';
bool tie = false;
string n1,n2;
void function2(){
  int digit;
  if(symbol == 'x'){
    cout<<n1<<", please enter : ";
    cin>>digit;
  }
  if(symbol == '0'){
    cout<<n2<<", please enter : ";
    cin>>digit;
  }

  if(digit == 1){
    row = 0; column = 0;
  }
  if(digit == 2){
    row = 0; column = 1;
  }
  if(digit == 3){
    row = 0; column = 2;
  }

  if(digit == 4){
    row = 1; column = 0;
  }
  if(digit == 5){
    row = 1; column = 1;
  }
  if(digit == 6){
    row = 1; column = 2;
  }

  if(digit == 7){
    row = 2; column = 0;
  }
  if(digit == 8){
    row = 2; column = 1;
  }
  if(digit == 9){
    row = 2; column = 2;
  }

  else if( digit < 1 || digit > 9 ){
    cout<<"invalid ! "<<endl;
  }

if(symbol == 'x' && blank[row][column] !='x' && blank[row][column] !='0'){
  blank[row][column] = 'x';
  symbol = '0';
}
else if(symbol == '0' && blank[row][column] !='x' && blank[row][column] !='0'){
  blank[row][column] = '0';
  symbol = 'x';
}
else{
  cout<<"there is no empty space "<<endl;
  function2();
}
function1();
}
bool function3(){
  for(int i = 0 ; i < 3 ; i++){
    if(blank[i][0] == blank[i][1] && blank[i][0] == blank[i][2] || blank[0][i] == blank[1][i] && blank[0][i] == blank[2][i] )
    {
      return true;
    }
    if(blank[0][0] == blank[1][1] && blank[1][1] == blank[2][2] || blank[0][2] == blank[1][1] && blank[1][1] == blank[2][0] )
    {
      return true;
    }
  }
  for(int i = 0 ; i < 3; i++)
  {
    for(int j = 0 ; j < 3; j++)
    {
      if(blank[i][j] != 'x' && blank[i][j] != '0')
      {
        return false;
      }
    }
  }
  tie = true ;
  return false;
}
int main(){
  cout << "enter the name of first player : \n";
  getline(cin,n1);
  cout<<"enter the name of second player : \n";
  getline (cin,n2);
  cout<<n1<<" is player 1 so he/she is play first. \n";
  cout<<n2<<" is player 2 so he/she is play second. \n";
  while(!function3()){
    function1();
    function2();
    function3();
  }
  if(symbol == 'x' & tie==false ){
    cout<<n2<<" wins !! " << endl;
  }
  if(symbol == '0' & tie == false ){
    cout<<n1<<" wins !! "<<endl;
  }

  }
