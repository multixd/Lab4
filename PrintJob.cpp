#include "PrintJob.h"

PrintJob::PrintJob ( int setP, int setJ, int numP ):priority(setP), jobNumber(setJ), numPages(numP){}
int PrintJob::getPriority ( ){
    return priority;
}

int PrintJob::getJobNumber ( ){
    return jobNumber;
}

int PrintJob::getPages ( ){
    return numPages;
}
void PrintJob::swap(PrintJob* next) {
	int pr = priority;
	int j = jobNumber;
	int p = numPages;
	priority = next -> priority;
	jobNumber = next -> jobNumber;
	numPages = next -> numPages;
	next -> priority = pr;
	next -> jobNumber = j;
	next -> numPages = p;
}


