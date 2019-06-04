#include<cstdio>
#define Maxsize 50
typedef int ElementType;
typedef struct{
    ElementType data[Maxsize];// 存放链表的位置
    int length;// 记录链表的长度
}SqList;
/*typedef struct{
    ElementType *data;
    int Maxsize,length;
}SqList;*/
// 其中L为顺序表，i为插入的位置， e为插入的元素
bool Listinsertion(SqList &L,int i,ElementType e){
    if(i<1||i>L.length+1){
        return false;
    }
    if(L.length>=Maxsize){
        return false;
    }
    for(int j=L.length;j>i;j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;// 在位置i处插入元素e,第i个位置插入对应着下标i-1
    L.length++;
    return true;
}
bool Listdelete(SqList &L,int i,ElementType &e){
    if(i<1||i>L.length){
        return false;
    }
    e = L.data[i-1];
    for(int j=i;j<L.length;j++){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}
int LocationElem(SqList &L,ElementType e){
    int i;
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return 0;
}
bool del_Min(SqList &L,ElementType &value){
    if(L.length==0){
        return false;
    }
    value = L.data[0];
    int pos = 0;
    for(int i=1;i<L.length;i++){
        if(L.data[i]<value){
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length-1];
    L.length--;
    return true;
}
void print_List(SqList &L){
    if(L.length==0){
        return;
    }
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
    return;
}
void Reverse(SqList &L){
    ElementType temp;
    for(int i=0;i<L.length/2;i++){
        temp = L.data[i];
        L.data[i] = L.data[L.length-i-1];// 考虑边界情况就知道要减1了；
        L.data[L.length-i-1] = temp;
    }
}
void del_x_1(SqList &L,ElementType x){
    int k=0;
    for(int i=0;i<L.length;i++){
        if(L.data[i]!=x){
            L.data[x] = L.data[i];
            k++;
        }
    }
    L.length = k;
}
bool Del_x_2t(SqList &L,ElementType s,ElementType t){
    int k=0;
    if(L.length==0||s>=t){
        return false;
    }
    for(int i=0;i<L.length;i++){
        if(L.data[i]>=s&&L.data[i]<=t){
            k++;
        }else{
        L.data[i-k] = L.data[i];
        }
    }
    L.length -=k;
    return true;
}
bool Del_s_t2(SqList &L,ElementType s,ElementType t){
    int i,j;
    if(s>=t||L.length==0)
        return false;
    for(i=0;i<L.length&&L.data[i]<s;i++);
    if(i>=L.length)
        return false;
    for(j=i;j<L.length&&L.data[j]<t;j++);
    for(;j<L.length;i++,j++)
        L.data[i] = L.data[j];
    L.length = i;
    return true;
}
bool Del_s_t(SqList &L,ElementType s,ElementType t){
    int i,k = 0;
    if(L.length==0||s>=t){
        return false;
    }
    for(i=0;i<L.length;i++){
        if(L.data[i]>=s&&L.data[i]<=t){
            k++;
        }else{
            L.data[i-k] = L.data[i];
        }
    }
    L.length-=k;
    return true;
}
// 删除有序链表中的重复元素
bool Del_Duplicated(SqList &L){
    if(L.length==0){
        return false;
    }
    for(int i=0,j=1;j<L.length;j++){
        if(L.data[i]!=L.data[j]){
            L.data[++i] = L.data[j];
        }
    }
    L.length = i+1;// i表示的是下标，所以要加上1才等于实际的长度
    return true;
}
typedef int DataType;
void Reverse(DataType A[],int left,int right,int arraySize){
    if(left>=right||right>=arraySize)
        return;
    int mid = left + (right-left)/2;
    for(int i=0;i<mid-left;i++){
        DataType temp = A[left+i];
        A[left+i] = A[right-i];
        A[right-i] = temp;
    }
}
void Exchange(DataType A[],int m,int n,int arraySize){
    Reverse(A,0,m+n-1,arraySize);
    Reverse(A,0,n-1,arraySize);
    Reverse(A,n,m+n-1,arraySize);
}
void searchExchange(ElementType A[],ElementType x,int n){
    int low =0,high = n-1,mid;
    while(low<high){
        mid = (low+high)/2;
        if(A[mid]==x) break;
        else if(A[mid]<x) low = mid+1;
        else high = mid-1;
    }
    if(A[mid]==x&mid!=n-1){
        t= A[mid];A[mid] = A[mid+1];A[mid+1] = t;
    }
    if(low>high){
        for(i=n-1;i>high;i--) A[i+1]=A[i];
        A[i+1]=x;// 这时候的high在low前面
    }
}
// 进行顺序表的翻转
void Reverse_list(int R[],int from,int to){
    int i,temp;
    for(int i=0;i<(to-from+1)/2;i++){
        temp = R[from+i];
        R[from+i] = R[to-i];
        R[to-i]  = temp;
    }
}
void Converse(int R[],int n,int p){
    Reverse_list(R,0,p-1);
    Reverse_list(R,p,n-1);
    Reverse_list(R,0,n-1);
}
int main(){
    SqList L;
    L.data[0] = 0;
    L.data[1] = 1;
    L.length = 10;
    bool a;
    for(int i=1;i<=10;i++){
        a= Listinsertion(L,i,i);
        printf("%d\n",a);
    }
    for(int i=0;i<10;i++){
        printf("%d ",L.data[i]);
    }
    return 0;
}
