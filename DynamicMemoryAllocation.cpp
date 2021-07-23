#include<bits/stdc++.h>
using namespace std;
int main()
{
  float *p;
  if(/*some condition to access teh dynamic memory*/)
  {
    p=(float*)(malloc(4));//the malloc function returns the address of memory allocated ie 4 bytes then also malloc return a void pointer so we need to type cast it
    //according to the pointer w type..so here we define it float and assign the address of 4 byte memory block in heap memory to float pointer p;..
    *p=3.4;//this way we assign value to our dynamic memory block ie a float value...
    int *p1;
    p1=calloc(5,2);//creates memeory of 5 block each of size 2 bytes....and returns the address of first block {[],[],[],[],[]}....
    //address is int type and our pointer is also int type.
    //pointers declaration is an example of static memeory allocation..
    //by default malloc when assigned has garbage values whereas calloc assigns all bloks as 0.
    *(p1+0)=34//assign value at 0th block in calloc type memeory allocation..{[34],[],[],[],[]}
    *(p+1)=55;//{[34],[55],[],[],[]}
    //Realloc helps in changing size of dynamic arrays made using calloc or malloc...
    void* realloc(void* block,int size)///this is how we use realloc.
      //example...
    double *q;
    q=realloc(p,8);//here we change the size of our malloc with pointer p to 8 bytes. ..the contents are coppied to new memory of 8 bytes..and new address is 
    //the address which realloc returns is stored in double q;
    free(p);//this function realeases the dynaic memory block after its used..and frees up the space we here have to specify the pointer address to our dynamic 
    //memory.
      
  }
  
}
