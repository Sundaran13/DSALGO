void Solution::arrange(vector<int> &A) {
    int n=A.size();
    for(int i=0;i<A.size();i++){
        A[i]+=(A[A[i]]%n)*n;
    }
    for(int i=0;i<n;i++){
        A[i]/=n;
    }
    return ;
}

///WE can change the positions of array elements without creating an extra space ;;
//hence we can alter the given array in O(1) space;;;;;;;;
"''''''"'"""'""""""""""""""""'''"'''''''''''''
