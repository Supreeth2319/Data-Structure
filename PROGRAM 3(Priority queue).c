#include<stdio.h>
#include<stdlib.h>

struct Process
{
    int pid;  // Process ID
    int bt;   // CPU Burst time required
    int priority; // Priority of this process
};
 typedef struct  Process proc;
proc pro[30],temp;
int n=0;

   void insert() 
  {
      int i=0,j=0;
        printf("\nEnter the process id, burst time and priority of the queue\n ");
        scanf("%d %d %d", &temp.pid,&temp.bt,&temp.priority);
       
        while(temp.priority<pro[i].priority)  //while loop to locate the position to insert
        i++;
        
        for(j=n-1; j>=i; j--) // to shift the items towards right to insert the element
            pro[j+1] = pro[j];
            
            pro[i] = temp;  // inserting
            n = n+1;         // increment number of items
        }
        
   void del() //deleting an array element
    { 
        int i,j,pid;
        printf("\nEnter the process id of the  element to be deleted: ");
        scanf("%d",&pid);
        //elem = a[pos];
        for(j=0;j<n;j++)
        if(pro[j].pid==pid)
        break;
        printf("  Deleted element is pid =%d\t\tburst time=%d\t\tpriority=%d\t\t\n",  pro[j].pid,pro[j].bt,pro[j].priority);

        for(i=j; i<n-1; i++)
        pro[i] = pro[i+1];

        n = n-1;

     }

          
    void findWaitingTime(int wt[])
       {
    // waiting time for first process is 0
        wt[0] = 0;
 
    // calculating waiting time
       for (int  i = 1; i < n ; i++ )
        wt[i] =  pro[i-1].bt + wt[i-1] ;
      }

// Function to calculate turn around time
void findTurnAroundTime(int wt[], int tat[])
  {
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int  i = 0; i < n ; i++)
        tat[i] = pro[i].bt + wt[i];
   }


//Function to calculate average time
void display()
 {  
     if(n==0)
     {
     printf("Priority Queue is empty\n");
     return;
     }
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    //Function to find waiting time of all processes
    findWaitingTime( wt);
 
    //Function to find turn around time for all processes
    findTurnAroundTime(wt, tat);
 
    //Display processes along with all details
    printf("\nProcesses     Burst time      Waiting time   Turn around time\n");
 
    // Calculate total waiting time and total turn
    // around time
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("   %d\t\t%d\t\t%d\t\t%d\n",  pro[i].pid,pro[i].bt,wt[i],tat[i]);
    }
 
    printf("\n Average waiting time=%f\n Average turnaround time=%f", (float)total_wt/(float)n,(float)total_tat / (float)n);
}
    
    void main()
    {
        int ch;
            do{
            printf("\n\n--------Menu-----------\n");
            printf("1.Create\n 2.Display\n  3.Delete\n 4.Exit\n");
            printf("-------------------------------");
            printf("\nEnter your choice: ");
            scanf("%d", &ch);
            switch(ch)
            {
           case 1: insert();
            break;
            case 2: display();
            break;
            case 3: del();
            break;
            case 4: exit(0);
            break;
            default: printf("\nInvalid choice:\n");
            break;
        }
    }while(ch!=5);
}


