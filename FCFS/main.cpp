#include<iostream>
#include<fstream>
using namespace std;
int main() {

	fstream file;
	int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    // bt: Burst time, wt: Waiting time, tat: Turnaround time,
    // avwt: Avarage Wating time, avtat: Avarage Turnaround time.
	wt[0]=0; // waiting time for first process is 0

	file.open("input.txt");
	file>>n;
	cout<<"\nTotal number of processes: "<<n<<endl;

	// read data from file "input.txt" (Burst Time)
	for(i= 0; i < n ;i++){
		file>>bt[i];
	}

	// display with Gantt Chart
	cout<<"\nGantt Chart: ";
	for(i = 0 ; i < n ; i++){
		cout<<"\tP["<<i+1<<"] ";
	} 
	// calculating waiting time
	cout<<"\n\n\t";
	for (i=0;i<n;i++) {
		wt[i]=0;
		for (j=0;j<i;j++)
		            wt[i] = wt[i] + bt[j];
					cout<<"\t  "<<wt[i];
	}

	cout<<"\n\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";  
	// calculating turnaround time
	for (i=0;i<n;i++) {
		tat[i]=bt[i]+wt[i];
		avwt+=wt[i];
		avtat+=tat[i];
		cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
	}
    // calculating avarage of Wating time n Turnaround time
	avwt = avwt/=i;
	avtat = avtat/=i;
	cout<<"\n\nAverage Waiting Time:"<<avwt;
	cout<<"\nAverage Turnaround Time:"<<avtat;


	file.close();	//close file

	return 0;
}