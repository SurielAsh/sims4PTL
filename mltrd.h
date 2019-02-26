//
// Created by nagi on 19-2-23.
//

#ifndef SIMS_MLTRD_H
#define SIMS_MLTRD_H
#include <thread>
#include <unistd.h>
#include <iostream>
#include "ptl_option.h"

using namespace std;

//template

void Dprt1(vector<ptl> &vptl,int n){
	vptl[1].ini(n);
	vptl[11].ini(n);
}
void Dprt2(vector<ptl> &vptl,int n){
	vptl[2].ini(n);
	vptl[12].ini(n);
}
void Dprt3(vector<ptl> &vptl,int n){
	vptl[3].ini(n);
	vptl[13].ini(n);
}
void Dprt4(vector<ptl> &vptl,int n){
	vptl[4].ini(n);
	vptl[14].ini(n);
}
void Dprt5(vector<ptl> &vptl,int n){
	vptl[5].ini(n);
	vptl[15].ini(n);
}
void Dprt6(vector<ptl> &vptl,int n){
	vptl[6].ini(n);
	vptl[16].ini(n);
}
void Dprt7(vector<ptl> &vptl,int n){
	vptl[7].ini(n);
	vptl[17].ini(n);
}
void Dprt8(vector<ptl> &vptl,int n){
	vptl[8].ini(n);
	vptl[18].ini(n);
}
void Dprt9(vector<ptl> &vptl,int n){
	vptl[9].ini(n);
	vptl[19].ini(n);
}
void Dprt10(vector<ptl> &vptl,int n){
	vptl[0].ini(n);
	vptl[10].ini(n);
}
void Dprt0(vector<ptl> &vptl,int n){
	thread t1(Dprt1,ref(vptl),n);
	thread t2(Dprt2,ref(vptl),n);
	thread t3(Dprt3,ref(vptl),n);
	thread t4(Dprt4,ref(vptl),n);
	thread t5(Dprt5,ref(vptl),n);
	thread t6(Dprt6,ref(vptl),n);
	thread t7(Dprt7,ref(vptl),n);
	thread t8(Dprt8,ref(vptl),n);
	thread t9(Dprt9,ref(vptl),n);
	thread t10(Dprt10,ref(vptl),n);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
}


void update1(vector<ptl> &vptl,int e1,int e2,int n,double w,vector<int> p)
{
	vptl[0].update(e1,e2,n,w,p);
	vptl[10].update(e1,e2,n,w,p);
}void update2(vector<ptl> &vptl,int e1,int e2,int n,double w,vector<int> p)
{
	vptl[1].update(e1,e2,n,w,p);
	vptl[11].update(e1,e2,n,w,p);
}void update4(vector<ptl> &vptl,int e1,int e2,int n,double w,vector<int> p)
{
	vptl[2].update(e1,e2,n,w,p);
	vptl[12].update(e1,e2,n,w,p);
}void update5(vector<ptl> &vptl,int e1,int e2,int n,double w,vector<int> p)
{
	vptl[4].update(e1,e2,n,w,p);
	vptl[14].update(e1,e2,n,w,p);
}void update6(vector<ptl> &vptl,int e1,int e2,int n,double w,vector<int> p)
{
	vptl[5].update(e1,e2,n,w,p);
	vptl[15].update(e1,e2,n,w,p);
}void update7(vector<ptl> &vptl,int e1,int e2,int n,double w,vector<int> p)
{
	vptl[6].update(e1,e2,n,w,p);
	vptl[16].update(e1,e2,n,w,p);
}void update8(vector<ptl> &vptl,int e1,int e2,int n,double w,vector<int> p)
{
	vptl[7].update(e1,e2,n,w,p);
	vptl[17].update(e1,e2,n,w,p);
}void update9(vector<ptl> &vptl,int e1,int e2,int n,double w,vector<int> p)
{
	vptl[8].update(e1,e2,n,w,p);
	vptl[18].update(e1,e2,n,w,p);
}void update10(vector<ptl> &vptl,int e1,int e2,int n,double w,vector<int> p)
{
	vptl[9].update(e1,e2,n,w,p);
	vptl[19].update(e1,e2,n,w,p);
}void update3(vector<ptl> &vptl,int e1,int e2,int n,double w,vector<int> p)
{
	vptl[3].update(e1,e2,n,w,p);
	vptl[13].update(e1,e2,n,w,p);
}
void update0(vector<ptl> &vptl,int e1,int e2,int n,double w,vector<int> p)
{
	thread t1(update1,ref(vptl),e1,e2,n,w,p);
	thread t2(update2,ref(vptl),e1,e2,n,w,p);
	thread t3(update3,ref(vptl),e1,e2,n,w,p);
	thread t4(update4,ref(vptl),e1,e2,n,w,p);
	thread t5(update5,ref(vptl),e1,e2,n,w,p);
	thread t6(update6,ref(vptl),e1,e2,n,w,p);
	thread t7(update7,ref(vptl),e1,e2,n,w,p);
	thread t8(update8,ref(vptl),e1,e2,n,w,p);
	thread t9(update9,ref(vptl),e1,e2,n,w,p);
	thread t10(update10,ref(vptl),e1,e2,n,w,p);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
}

#endif //SIMS_MLTRD_H
