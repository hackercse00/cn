#include<stdio.h>
#include<math.h>
int sender();
int reciver();
int btd(int*,int);
void main(){
	int s;
	printf("Enter 1 for sender or 2 for reciever : ");
	scanf("%d",&s);
	if(s==1){
		sender();
	}
	else{
		reciever();
	}
}
int sender(){
	int a[32],i,cw[38],k=0,c=0,j=0,n,x,rr[6][30],count=0,l;
	printf("Enter the actual 32 bit data :");
	for(i=0;i<32;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<38;i++){
		if(i+1==pow(2,k)){
			cw[i]=2;
			k++;
		}
		else{
			cw[i]=a[j];
			j++;
		}
	}
	while(pow(2,c)<=38){
    	x=pow(2,c);
    	l=x,n=0;
    	while(l<=38){
            for(i=0;i<x && l<=38;i++){
		        rr[c][n]=cw[l-1];
		        n++;
		        l++;
	        }
	        for(i=0;i<x && l<=38;i++){
		        l++;
		    }
	    }
	    c++;
    }
    for(i=0;i<6;i++){
		count=0;
		for(j=0;j<=38 && rr[i][j]<=38;j++){
			if(rr[i][j]==1){
				count++;
			}
		}
		if(count%2==0){
			cw[(int)pow(2,i)-1]=0;
		}
		else{
			cw[(int)pow(2,i)-1]=1;
		}
	}
	printf("The code word is : ");
	for(i=0;i<38;i++){
		printf("%d ",cw[i]);
	}
	printf("\n");
}
int reciever(){
	int i,b,r[38],a[32],cw[38],k=0,c=0,j=0,n,x,rr[6][20],count=0,l,arr[6];
	printf("Enter the code word recieved : ");
	for(i=0;i<38;i++){
		scanf("%d",&cw[i]);
	}
	while(pow(2,c)<=38){
    	x=pow(2,c);
    	l=x,n=0;
    	while(l<=38){
            for(i=0;i<x && l<=38;i++){
		        rr[c][n]=cw[l-1];
		        n++;
		        l++;
	        }
	        for(i=0;i<x && l<=38;i++){
		        l++;
		    }
	    }
	    c++;
    }
	printf("\n");
    for(i=0;i<6;i++){
		count=0;
		for(j=0;j<=19 && rr[i][j]<=38;j++){
			if(rr[i][j]==1){
				count++;
			}
		}
		if(count%2==0){
			arr[6-i-1]=0;
		}
		else{
			arr[6-i-1]=1;
		}
	}
	if(btd(arr,6)==0){
		printf("The code word is error free\n");
		printf("The data is : ");
	}
	else{
	    printf("Error position is : %d",btd(arr,6));
	    if(btd(arr,6)==0){
	    	cw[btd(arr,6)]=1;
		}
		else{
			cw[btd(arr,6)]=0;
		}
		c=0;
	    printf("\n");
	    printf("After the error correction : ");
	}
	    for(i=0;i<38;i++){
	        if(pow(2,c)==i+1){
	        	c++;
			}
	        else{
		        printf("%d ",cw[i]);
	        }		
        }
}
int btd(int d[],int z){
	int i=z-1,sum=0;
	while(i>=0){
		sum=sum+(d[i]*pow(2,z-i-1));
		i--;
	}
	return sum;
}
