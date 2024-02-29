1	#include<graphics.h>
2	#include<stdlib.h>
3	#include<stdio.h>
4	#include<conio.h>
5	#include<dos.h>
6	#include<math.h>
7	#include<fstream.h>
8	#include<string.h>
9	union REGS i,o;
10	int flag;
11	int  ansbox1=0,ansbox2=0;
12	int  life1=0,life2=0,life3=0,f3=0;
13	int button, x1,y1; 14
15
16	long double size; 17
18	char  str[8]={'0'};
19	char  total[10]={'0'};
20	long  double  p=500;
21	ifstream  fin;
22	char correctans[2]; 23
24	void page2();
25	void page3();
26	void line();
27	void questions();
28	void incorrect1();
29	void incorrect2();
30	void incorrect3();
31	void incorrect4();
32	void phonefriend();
33	void fiftyfifty();
34	void audiencepoll();
35	void sorry();
36	void select();
37	void correct();
38	void startscreen();
39	void  totalprizemoney();
40	void  music();
41	void  askname();
42	int  offset=0,num;
43	int  prev[15],count=0; 44
45	initmouse() 46	{
47	i.x.ax=0;
48	int86(0x33,&i,&o);
49	return(o.x.ax); 50	}
51	void  showmouseptr() 52	{
53	i.x.ax=1;
54	int86(0x33,&i,&o);
55	}
56	void  hidemouseptr() 57	{
58	i.x.ax=2;
59	int86(0x33,&i,&o);
60	}
61	void  getmousepos(int  *button,int  *x,int  *y) 62	{
63	i.x.ax=3;
64	int86(0x33,&i,&o);
65	*button=o.x.bx;
66	*x=o.x.cx;
67	*y=o.x.dx;
68	}
69
70
71
72	void  main() 73	{
74
75	/* request auto detection */
76	int  gdriver  =  DETECT,  gmode,  errorcode; 77
78
79
80	/* initialize graphics and local variables */
81	initgraph(&gdriver,  &gmode,  "c:\\turboc3\\bgi"); 82
83	/* read result of initialization */
84	errorcode = graphresult();
85	if  (errorcode  !=  grOk)     /*  an  error  occurred  */ 86	{
87	printf("Graphics  error:  %s\n",grapherrormsg(errorcode));
88	printf("Press  any  key  to  halt:");
89	getch();
90	exit(1);  /*  terminate  with  an  error  code  */ 91	}
92
 
93
94
95	if(initmouse()==0)
96	{
97	closegraph();
98	restorecrtmode();
99	//to  go  back  to  normal  graphics  mode  or  deleting  viewport.
100	printf(" mouse driver not loaded");
101	exit(1);
102	}
103	startscreen(); 104
105	p=500;
106	ansbox1=0,ansbox2=0;
107	count=0;
108	life1=0,life2=0,life3=0;
109	page2(); 110
111	hidemouseptr();
112	page3();
113	closegraph();
114	restorecrtmode();
115	} 116
117	void page2()
118	{
119	cleardevice();
120	settextstyle(12,0,5);
121	setcolor(10);
122	outtextxy(20,10,"KANHAIYA  LAL	Project  Coding");
123	setlinestyle(1,0,1); 124
125	setcolor(BLUE);
126	setlinestyle(0,0,3);
127	rectangle(500,5,625,350);
128	line(0,350,625,350);
129	setcolor(LIGHTBLUE);
130	int  poly[]={40,390,60,365,560,365,580,390,560,415,60,415,40,390};
131	drawpoly(7,poly);
132	line(0,390,40,390);line(580,390,620,390);
133	int  poly1[]={40,430,50,420,290,420,300,430,290,445,50,445,40,430};
134	drawpoly(7,poly1);
135	int  poly2[]={300,430,310,420,575,420,585,430,575,445,310,445,300,430};
136	drawpoly(7,poly2);
137	int  poly3[]={40,465,50,450,290,450,300,465,290,475,50,475,40,465};
138	drawpoly(7,poly3);
139	int  poly4[]={300,465,310,450,575,450,585,465,575,475,310,475,300,465};
140	line(0, 430,40,430);line(0,465,40,465);
141	line(585,430,620,430);line(585,465,620,465);
142	drawpoly(7,poly4);
143	setfillstyle(1,RED);
144	settextstyle(2,0,0);
145	fillellipse(525,20,20,10);
146	fillellipse(565,20,20,10);
147	fillellipse(605,20,20,10);
148	setcolor(YELLOW);
149	outtextxy(510,15,"50:50");
150	outtextxy(550,15,"PHONE");
151	outtextxy(589,13,"PUBLIC");
152	outtextxy(593,18,"vote");
153	settextstyle(12,0,2);
154	setcolor(YELLOW);
155	outtextxy(520,50,"	10000000");
156	setcolor(LIGHTBLUE);
157	outtextxy(520,70,"	5000000");
158	outtextxy(520,90,"	2500000");
159	outtextxy(520,110,"	1250000");
160	outtextxy(520,130,"	640000");
161	setcolor(YELLOW);
162	outtextxy(520,150,"	320000");
163	setcolor(LIGHTBLUE);
164	outtextxy(520,170,"	160000");
165	outtextxy(520,190,"	80000");
166	outtextxy(520,210,"	40000");
167	outtextxy(520,230,"	20000");
168	setcolor(YELLOW);
169	outtextxy(520,250,"	10000");
170	setcolor(LIGHTBLUE);
171	outtextxy(520,270,"	5000");
172	outtextxy(520,290,"	3000");
173	outtextxy(520,310,"	2000");
174	outtextxy(520,330,"	1000");
175
176	count=0; 177
178	askname(); 179
180	questions(); 181
182
183
184	getch(); 185
 
186	}
187	void page3()
188	{
189	cleardevice();
190	settextstyle(12,0,1);
191	for(int  i=490;i>=200;i--)
192	{
193	setcolor(10); 194
195	}
196	setcolor(10);
197	setcolor(WHITE);
198	outtextxy(10,460,"PRESS  ANY  KEY  TO  CONTINUE  ");
199	getch(); 200
201	exit(0);
202	}
203	char  proc[]={"PROCESSING 	"};
204	void line()
205	{
206	setlinestyle(0,0,1);
207	for(int  x=0;x<=485;x++)
208	{	setcolor(LIGHTGRAY);
209	line(x+10,20,x+10,340);
210
211	setcolor(0);
212	rectangle(0,20,x,340);
213	line(x+10,20,x+10,340);
214
215	}
216	setlinestyle(0,0,3);
217	sleep(1); 218
219	}
220	void questions()
221	{
222	char question[200];
223	char ans1[150];
224	char ans2[150];
225	char ans3[150];
226	char ans4[150]; 227
228	int  temp=0; 229
230
231
232	char ch,ch1;
233	int  num=0,ct=0,i=0,t=0;
234	int  randnum[15];
235	char  str[4],co[4],numc[2]; 236
237	randomize(); 238
239	fin.open("KBC.txt",ios::binary);
240	while(!fin.eof())
241	{
242	fin.get(ch);
243	if(ch=='\n')
244	t++;
245	}
246	fin.close();
247	t=t/6;
248
249	fin.open("KBC.txt",ios::binary);
250	settextstyle(COMPLEX_FONT,0,3);
251	setcolor(RED);
252	outtextxy(150,310,"LET's  PLAY  !!!!");
253	sleep(3);
254	setcolor(BLACK);
255	outtextxy(150,310,"LET's  PLAY  !!!!"); 256
257	while(ct<15)
258	{
259
260	count=0;
261	num=random(t); 262
263	for(i=0;i<temp;i++)
264	{
265	if(randnum[i]==num)
266	{
267	num=random(t); 268		i=0;
269	}
270	}
271	randnum[temp]=num; 272
273	temp++; 274
275	fin.seekg(0,ios::beg);
276	while(!fin.eof())
277	{
278	fin.get(ch);
 
279	if(ch=='\n')
280	count++;
281	if(count==(6*num))
282	{
283	
284	break;
285	}
286	}	if(ct>0)
287	{
288	setcolor(RED);
289	outtextxy(150,310,"NEXT  question!!!!");
290	sleep(3);
291	setcolor(BLACK);
292	outtextxy(150,310,"NEXT  question!!!!");
293	}
294
295	fin.getline(question,200,'\n');
296	fin.getline(ans1,150,'\n');
297	fin.getline(ans2,150,'\n');
298	fin.getline(ans3,150,'\n');
299	fin.getline(ans4,150,'\n');
300	fin.getline(correctans,2,'\n'); 301
302	if(strlen(question)>=40||strlen(ans1)>=25||strlen(ans2)>=25||strlen(ans3)>=25||strlen(ans4)>=25)
303	settextstyle(COMPLEX_FONT,0,1);
304	else
305	settextstyle(COMPLEX_FONT,0,2); 306
307	setcolor(RED);
308	setcolor(15); 309
310
311	outtextxy(60,375,question);
312	outtextxy(60,415,ans1);
313	outtextxy(320,415,ans2);
314	outtextxy(60,445,ans3);
315	outtextxy(320,445,ans4);
316	showmouseptr();
317	if(correctans[0]=='a')
318	{
319	incorrect1();
320	}
321	else  if(correctans[0]=='b')
322	{
323	incorrect2();
324	}
325	else  if(correctans[0]=='c')
326	{
327	incorrect3();
328	}
329	else  if(correctans[0]=='d')
330	{
331	incorrect4();
332	}
333
334
335	ct++;
336	}
337	if(ct==15)
338	totalprizemoney();
339	fin.close(); 340
341	} 342
343
344	void incorrect1() 345
346
347	{
348	count++;
349	showmouseptr();
350	flag=0;
351	select();
352	while(flag==0)
353	{
354	getmousepos(&button,&x1,&y1);
355	if((button & 1)==1)
356	{
357	if((x1>=0&&x1<=300)&&(y1>=420&&y1<=445))
358	correct();
359	else  if((x1>=300&&x1<=585&&y1>=420&&y1<=445)||(x1>=0&&x1<=300&&y1>=450&&y1<=475)||(x1>=300&&x1<=585&&y1>=450&&y1<=475))
360	sorry();
361	}
362	}
363	} 364
365
366	void incorrect2() 367
368	{	count++;
369	showmouseptr();
370	flag=0;
371	select();
 
372		while(flag==0)
373		{
374		
375		getmousepos(&button,&x1,&y1);
376		if((button & 1)==1)
377		{
378		
379		if((x1>=300&&x1<=585)&&(y1>=420&&y1<=445))
380		correct();
381		else  if  ((x1>=0&&x1<=300&&y1>=420&&y1<=445)||(x1>=0&&x1<=300&&y1>=450&&y1<=475)||(x1>=300&&x1<=585&&y1>=450&&y1<=475))
382		sorry();
383		}
384	}	
385		
386	}	
387		void incorrect3()
388	{	count++;
389		showmouseptr();
390		flag=0;
391		select();
392		while(flag==0)
393		{
394		getmousepos(&button,&x1,&y1);
395		if((button & 1)==1)
396		{
397		if((x1>=0&&x1<=300)&&(y1>=450&&y1<=475))
398		correct();
399		else     if((x1>=0&&x1<=300&&y1>=420&&y1<=445)||(x1>=300&&x1<=585&&y1>=420&&y1<=445)||(x1>=300&&x1<=585&&y1>=450&&y1<=475))
400		sorry();
401		}
402		}
403		
404	}	
405		void incorrect4()
406	{	count++;
407		showmouseptr();
408		flag=0;
409		select();
410		while(flag==0)
411		{
412		getmousepos(&button,&x1,&y1);
413		if((button & 1)==1)
414		{
415		if((x1>=300&&x1<=585)&&(y1>=450&&y1<=475))
416		correct();
417		else  if((x1>=0&&x1<=300)&&(y1>=420&&y1<=445)||(x1>=300&&x1<=585&&y1>=420&&y1<=445)||(x1>=0&&x1<=300&&y1>=450&&y1<=475))
418		sorry();
419		}
420		}
421		
422		
423		
424	}	
425		
426		char  prevstr[10]={"1000"};
427		void correct()
428		{
429		
430		hidemouseptr();
431		flag=1;
432		
433		p=p*2;
434		if(p==4000)
435		p=3000;
436		if(p==6000)
437		p=5000;
438		if(p==1280000)
439		p=1250000;
440		
441		
442		ltoa(p,str,10);
443		
444		sleep(2);
445		setcolor(BLUE);
446		setfillstyle(1,YELLOW);
447		line(0,250,40,250);line(460,250,500,250);
448		
449	int  pol[]={40,250,60,235,460,235,480,250,460,265,60,265,40,250};
450	fillpoly(7,pol); 451
452	setcolor(BLUE);
453	settextstyle(0,0,3);
454	outtextxy(200,240,str);
455	settextstyle(0,0,1);
456	setcolor(WHITE); 457
458
459	setcolor(BLACK);
460	setfillstyle(1,BLACK);
461	settextstyle(0,0,1); 462
463	if(ansbox2==1)
464	{
 
465	bar(503,345+ansbox1,622,360+ansbox1);
466	setcolor(WHITE);
467	outtextxy(520,350+ansbox1,"  ");
468	outtextxy(540,350+ansbox1,prevstr);
469	}
470	setcolor(RED);
471	ansbox2=1;
472	setfillstyle(1,RED);
473	setcolor(WHITE);
474	settextstyle(0,0,1);
475	ansbox1=ansbox1-20;
476	bar(503,345+ansbox1,622,360+ansbox1);
477	outtextxy(520,350+ansbox1,"  ");
478	outtextxy(540,350+ansbox1,str); 479
480	ltoa(p,prevstr,10);
481	if(p==10000||p==320000||p==10000000)
482	music(); 483
484	sleep(1);
485	setcolor(BLACK);
486	setfillstyle(1,BLACK);
487	bar3d(0,230,495,270,0,1);
488
489
490	settextstyle(COMPLEX_FONT,0,2);
491	setcolor(RED); 492
493	sleep(1);
494	setcolor(LIGHTBLUE);
495	setfillstyle(1,BLACK); 496
497	int  poly[]={40,390,60,365,560,365,580,390,560,415,60,415,40,390};
498	fillpoly(7,poly);
499	line(0,390,40,390);line(580,390,620,390);
500	int  poly1[]={40,430,50,420,290,420,300,430,290,445,50,445,40,430};
501	fillpoly(7,poly1);
502	int  poly2[]={300,430,310,420,575,420,585,430,575,445,310,445,300,430};
503	fillpoly(7,poly2);
504	int  poly3[]={40,465,50,450,290,450,300,465,290,475,50,475,40,465};
505	fillpoly(7,poly3);
506	int  poly4[]={300,465,310,450,575,450,585,465,575,475,310,475,300,465};
507	line(0, 430,40,430);line(0,465,40,465);
508	line(585,430,620,430);line(585,465,620,465);
509	fillpoly(7,poly4); 510
511
512	} 513
514
515	void sorry()
516	{
517	hidemouseptr(); 518
519	sleep(1);
520	setcolor(BLUE);
521	settextstyle(0,0,3);
522	outtextxy(50,200,"SORRY  !  INCORRECT");
523	sleep(2);
524	fin.close(); 525
526	clearviewport();
527	setcolor(BLUE); 528
529	totalprizemoney(); 530
531	}
532	void  totalprizemoney()
533	{ 534
535	hidemouseptr();
536	clearviewport();
537	setcolor(BLUE);
538	setfillstyle(1,YELLOW);
539	line(0,390,40,390);line(580,390,620,390);
540	int  pol[]={40,390,60,365,560,365,580,390,560,415,60,415,40,390};
541	fillpoly(7,pol);
542	setcolor(RED);
543	settextstyle(0,0,2);
544	outtextxy(70,380,"Total  prize  money:");
545	setcolor(BLUE);
546	outtextxy(360,380,str);
547	settextstyle(0,0,1);
548	setcolor(GREEN);
549	outtextxy(100,430,"USE  THE  KEYBOARD  ARROW  KEYS  TO  SELECT");
550	setfillstyle(1,YELLOW);
551	bar(80,445,150,460);
552	char  a=0,x='E';int  flg=0;
553	do
554	{
555	outtextxy(100,450,"REPLAY	EXIT");
556	a=getch();
557	switch(a)
 
558
559
560
561
 
{
case 13 :
 



if((flg%2)==0)
 
562	x='R';
563	else
564	x='E';
565	break;
566
567
568	case 77:
569	case 75:
570	if((flg%2)==0)
571	{
572	setfillstyle(1,0);
573	bar(80,445,150,460);
574	setfillstyle(1,YELLOW);
575	bar(200,445,270,460);
576	}
577	else
578	{
579	setfillstyle(1,0);
580	bar(200,445,270,460);
581	setfillstyle(1,YELLOW); 582		bar(80,445,150,460);
583	}
584	break;
585	}
586	if(a==75||a==77)
587	flg++;
588	}while(a!=13);
589
590	if(x=='R')
591	{
592	clearviewport();
593	closegraph();
594	main();
595	}
596
597	else	if(x=='E')
598	{
599		page3(); 600	closegraph(); 601	exit(0);
602	}
603	}
604
605
606
607	void pass(int poly[14]) 608	{
609	setfillstyle(1,LIGHTBLUE);
610	setcolor(LIGHTBLUE);
611	drawpoly(7,poly);
612	ellipse(605,20,0,360,20,10);
613	ellipse(525,20,0,360,20,10);
614	ellipse(565,20,0,360,20,10);
615
616	setfillstyle(1,YELLOW);
617	setcolor(YELLOW);
618
619	}
620
621	void select()
622	{
623
624	int  polygon1[]={40,430,50,420,290,420,300,430,290,445,50,445,40,430};
625	int  polygon2[]={300,430,310,420,575,420,585,430,575,445,310,445,300,430};
626	int  polygon3[]={40,465,50,450,290,450,300,465,290,475,50,475,40,465};
627	int  polygon4[]={300,465,310,450,575,450,585,465,575,475,310,475,300,465};
628	setcolor(RED);
629	setfillstyle(1,RED);
630	setlinestyle(1,0,15);
631
632
633
634
635	do
636	{
637	settextstyle(3,0,2);
638	setcolor(BLACK);
639	outtextxy(30,270,"LIFELINE  TAKEN  ALREADY");
640	x:
641	getmousepos(&button,&x1,&y1);
642
643	if(x1>=0&&x1<=300&&y1>=420&&y1<=445)
644	{
645
646	pass(polygon2);
647	pass(polygon3);
648	pass(polygon4);
649	drawpoly(7,polygon1);
650	}
 
651
652
653	else  if(x1>=300&&x1<=585&&y1>=420&&y1<=445)
654	{
655
656	pass(polygon1);
657	pass(polygon3);
658	pass(polygon4);
659	drawpoly(7,polygon2);
660
661
662
663
664	}
665
666	else  if(x1>=0&&x1<=300&&y1>=450&&y1<=475)
667	{
668
669	pass(polygon1);
670	pass(polygon2);
671	pass(polygon4);
672	drawpoly(7,polygon3);
673	/*
674	putimage(50,425,arrow1,1);
675	putimage(330,425,arrow1,1);
676	putimage(50,455,arrow,1);
677	putimage(330,455,arrow1,1);
678	*/
679
680
681
682	}
683
684
685	else  if(x1>=300&&x1<=585&&y1>=450&&y1<=475)
686	{
687
688	pass(polygon1);
689	pass(polygon3);
690	pass(polygon2);
691	drawpoly(7,polygon4);
692	}
693
694
695	//select  lifeline.................................
696
697	//50:50
698	else  if(x1>=505&&x1<=545&&y1>=10&&y1<=30)
699	{
700
701	if(life1==1&&(button  &1)==1)
702	{
703	settextstyle(3,0,2);
704	setcolor(YELLOW);
705	outtextxy(30,270,"LIFELINE  TAKEN  ALREADY");
706
707
708	goto x;
709	}
710
711	setcolor(YELLOW);
712	ellipse(525,20,0,360,20,10);
713	setcolor(LIGHTBLUE);
714	ellipse(605,20,0,360,20,10);
715	ellipse(565,20,0,360,20,10);
716	fiftyfifty();
717	goto x;
718
719	}
720	//Phone  a  friend 721
722
723	else  if(x1>=545&&x1<=585&&y1>=10&&y1<=30)
724	{
725
726
727
728	if(life2==1&&(button  &1)==1)
729	{
730	settextstyle(3,0,2);
731	setcolor(YELLOW);
732	outtextxy(30,270,"LIFELINE  TAKEN  ALREADY");
733
734
735	goto x;
736	}
737
738	setcolor(YELLOW);
739	ellipse(565,20,0,360,20,10);
740
741	setcolor(LIGHTBLUE);
742	ellipse(605,20,0,360,20,10);
743	ellipse(525,20,0,360,20,10);
 
744	phonefriend();
745	goto x;
746	}
747
748	//audience poll
749	else  if(x1>=585&&x1<=625&&y1>=10&&y1<=30)
750	{
751	if(life3==1&&(button  &1)==1)
752	{
753	settextstyle(3,0,2);
754	setcolor(YELLOW);
755	outtextxy(30,270,"LIFELINE  TAKEN  ALREADY");
756
757	goto x;
758	}
759
760	setcolor(YELLOW);
761	ellipse(605,20,0,360,20,10);
762
763	setcolor(LIGHTBLUE);
764	ellipse(565,20,0,360,20,10);
765	ellipse(525,20,0,360,20,10);
766	audiencepoll();
767	goto x;
768	}
769
770	}
771	while((button  &  1)!=1);
772
773
774	}
775
776
777
778	void startscreen()
779	{
780
781	setlinestyle(0,0,3);
782	setcolor(BLUE);
783	setfillstyle(1,BLUE);
784	circle(300,225,225);
785	floodfill(300,200,BLUE);
786	setcolor(LIGHTBLUE);
787	setfillstyle(1,LIGHTBLUE);
788	circle(300,225,185);
789	floodfill(300,200,LIGHTBLUE);
790	setcolor(0);
791	setfillstyle(SLASH_FILL,0);
792	setlinestyle(1,0,0);
793	for(int  p=0;p<=185;p++)
794	{
795	circle(300,225,p);
796	delay(10);
797
798	}
799
800	setlinestyle(1,0,3);
801	setcolor(BLUE);
802	setfillstyle(7,BLUE);
803	fillellipse(300,225,30,185);
804	fillellipse(300,225,185,30);
805	setcolor(BLUE);
806	setcolor(15);
807	setfillstyle(1,15);
808
809	setcolor(15);
810	settextstyle(8,0,5);
811
812	settextstyle(0,0,3);
813
814	outtextxy(100,125,"K");
815	outtextxy(125,85,"A");
816	outtextxy(155,55,"U");
817	outtextxy(195,25,"N");
818	outtextxy(300,10,"B");
819	outtextxy(350,20,"A");
820	outtextxy(395,35,"N");
821	outtextxy(435,65,"E");
822	outtextxy(465,105,"G");
823	outtextxy(485,140,"A");
824	setcolor(YELLOW);
825	outtextxy(495,180," ");
826	outtextxy(85,180," ");
827	outtextxy(495,250," ");
828	outtextxy(85,250," ");
829	setcolor(15);
830	outtextxy(100,305,"K");
831	outtextxy(125,345,"A");
832	outtextxy(155,375,"U");
833	outtextxy(195,405,"N");
834	outtextxy(300,420,"B");
835	outtextxy(350,415,"A");
836	outtextxy(395,395,"N");
 
837	outtextxy(435,365,"E");
838	outtextxy(465,335,"G");
839	outtextxy(485,290,"A");
840	setlinestyle(1,0,3);
841	setcolor(5);
842	setfillstyle(0,5);
843	circle(300,225,185);
844	settextstyle(12,0,5);
845	setcolor(10);
846	outtextxy(510,470,"KANHAIYA  LAL");
847	setlinestyle(1,0,1);
848
849
850	setcolor(15);
851	settextstyle(8,0,5);
852	outtextxy(265,195," E "); 853	sound(1000);
854	delay(600);
855 outtextxy(215,195," R "); 856 outtextxy(315,195," P "); 857
858	sound(1100);
859	delay(600);
860	sound(1200);
861	delay(500);
862
863 outtextxy(170,195," O "); 864 outtextxy(365,195," A "); 865	sound(1000);
866	delay(500);
867	sound(1100);
868	delay(550);
869
870	outtextxy(115,195," R "); 871	outtextxy(400,195," T "); 872		sound(1200);
873	delay(450);
874	sound(1350);
875	delay(450);
876
877	outtextxy(85,195,"C  ");
878	outtextxy(500,195,"I");
879	sound(1500);
880	delay(1000);
881
882	nosound();
883	settextstyle(0,0,1);
884	outtextxy(10,460,"PRESS  ANY  KEY  TO  CONTINUE  ");
885	getch();
886
887	}
888
889	void  music()
890	{
891
892	sound(1000);
893	delay(600);
894
895	sound(1100);
896	delay(600);
897	sound(1200);
898	delay(500);
899
900	sound(1000);
901	delay(500);
902	sound(1100);
903	delay(550);
904
905	sound(1200);
906	delay(450);
907	sound(1350);
908	delay(450);
909
910	sound(1500);
911	delay(1000);
912	nosound();
913
914	}
915
916
917	void  askname()
918	{
919	settextstyle(0,0,1);
920	setcolor(7);
921	outtextxy(0,90,"WELCOME  TO  THE  COMPUTER  VERSION  OF  kaun  banega  crorepati"); 922	outtextxy(0,115,"please  enter your name	: ");
923	char  name[40];
924	gotoxy(30,8);
925	cin.getline(name,40);
926	outtextxy(0,150,"please enter your city	: "); 927	char city[40];
928	gotoxy(30,10);
929	cin.getline(city,40);
 
930
931
932
933
934
935
936
937
938
939
940
941
942
943
944
945
946
947
948
949
950
951
952
953
954
955
956
957
958
959
960
961
962
963
964
965
966
967
968
969
970
971
972
973
974
975
976
977
978
979
980
981
982
983
984
985
986
987
988
989
990
991
992
993
994
995
996
997
998
999
1000
1001
1002
1003
1004
1005
1006
1007
1008
1009
1010
1011
1012
1013
1014
1015
1016
1017
1018
1019
1020
1021
1022
 
sleep(1);

line();
sleep(1); setcolor(7);
outtextxy(10,90,"LET'S  WELCOME     ");
outtextxy(270,110," FROM "); setcolor(RED); outtextxy(150,90,name); outtextxy(320,110,city); setcolor(LIGHTGREEN);
outtextxy(0,150,"IMPORTANT  INSTRUCTIONS     ");
sleep(2); setcolor(LIGHTGRAY);
outtextxy(0,170,"USE  THE  MOUSE  TO  PLAY  THE  GAME.     ");
sleep(2); setcolor(LIGHTGREEN);
outtextxy(0,190,"PLEASE  CLICK  AND  HOLD  THE  LEFT  MOUSE  BUTTON  TO  SELECT.");
sleep(2); setcolor(LIGHTGRAY);
outtextxy(0,210,"YOU  HAVE  3  LIFELINES(AS  INDICATED  ON  THE  UPPER  RIGHT  CORNER)."); outtextxy(0,230,"CLICK  ON  THE  LIFELINES  TO  SELECT  THEM.");
sleep(2);
outtextxy(0,250,"THE  FILE  KBC.TXT  IS  AN  EVER  EXPANDABLE  QUESTION  BANK.."); outtextxy(0,260,"PLEASE  STICK  ON  TO  THE  FORMAT  USED  IN  THE  FILE  WHILE..  "); outtextxy(100,270,"EXPANDING  THE  QUESTION  BANK"  );
setcolor(WHITE); sleep(2); settextstyle(0,0,1);
outtextxy(0,320,"PRESS  ANY  KEY  TO  CONTINUE  ");


getch();

line(); settextstyle(BOLD_FONT,0,1);
}


void phonefriend()
{

settextstyle(3,0,2); setcolor(BLACK);
outtextxy(30,270,"LIFELINE  TAKEN  ALREADY");

if(((button  &1)==1)&&life2==0)
{
hidemouseptr(); setcolor(LIGHTBLUE); settextstyle(0,HORIZ_DIR,2);
outtextxy(30,250,"PHONE  A  FRIEND 	");
sleep(1);
outtextxy(30,270,"YOUR  TIME  STARTS.....NOW  ");
sleep(1);
line(); setcolor(LIGHTGRAY); setfillstyle(2,RED); circle(300,200,100); char arc[10];

settextstyle(0,HORIZ_DIR,5); int  x=0; setfillstyle(1,DARKGRAY); for(int  i=0;i<=30;i++)
{
setcolor(BLACK); pieslice(300,200,0,i*12,97); itoa(i,arc,10); setcolor(BLUE);
if(i>=10) x=25;
outtextxy(280-x,180,arc); sleep(1); setcolor(BLACK); outtextxy(280-x,180,arc);
}
life2=1; setcolor(YELLOW);
settextstyle(3,HORIZ_DIR,3);
outtextxy(0,315,"YOUR  TIME  ENDS  HERE.CLICK  AN  ANSWER");
sleep(3);
line();

showmouseptr();
}

}
void fiftyfifty()
{
settextstyle(3,0,2); setcolor(BLACK);
outtextxy(30,270,"LIFELINE  TAKEN  ALREADY");
 
1023
1024
1025
1026
1027
1028
1029
1030
1031
1032
1033
1034
1035
1036
1037
1038
1039
1040
1041
1042
1043
1044
1045
1046
1047
1048
1049
1050
1051
1052
1053
1054
1055
1056
1057
1058
1059
1060
1061
1062
1063
1064
1065
1066
1067
1068
1069
1070
1071
1072
1073
1074
1075
1076
1077
1078
1079
1080
1081
1082
1083
1084
1085
1086
1087
1088
1089
1090
1091
1092
1093
1094
1095
1096
1097
1098
1099
1100
1101
1102
1103
1104
1105
1106
1107
1108
1109
1110
1111
1112
1113
1114
1115
 

randomize();
int  r1=0,r2=0;
if(((button  &1)==1)&&life1==0)
{

setcolor(LIGHTBLUE); settextstyle(0,HORIZ_DIR,2); outtextxy(30,250,"50:50  LIFELINE  ");
sleep(1);
outtextxy(0,270,"TWO  WRONG  CHOICES  WILL"); outtextxy(280,290,"BE  ELIMINATED");
sleep(1);
line();

if(correctans[0]=='a')
{
while(r1==0||r2==0||r1==r2)
{
r1=random(4); r2=random(4);
}
}
if(correctans[0]=='b')
{
while(r1==1||r2==1||r1==r2)
{
r1=random(4); r2=random(4);
}
}
if(correctans[0]=='c')
{
while(r1==2||r2==2||r1==r2)
{
r1=random(4); r2=random(4);
}
}
if(correctans[0]=='d')
{
while(r1==3||r2==3||r1==r2)
{
r1=random(4); r2=random(4);
}
}
setcolor(BLACK); setfillstyle(1,BLACK);
int  poly1[]={40,430,50,420,290,420,300,430,290,445,50,445,40,430};
int  poly2[]={300,430,310,420,575,420,585,430,575,445,310,445,300,430};
int  poly3[]={40,465,50,450,290,450,300,465,290,475,50,475,40,465};
int  poly4[]={300,465,310,450,575,450,585,465,575,475,310,475,300,465};

if(r1==0) fillpoly(7,poly1);

else  if(r1==1) fillpoly(7,poly2);

else  if(r1==2) fillpoly(7,poly3);

else  if(r1==3) fillpoly(7,poly4);

if(r2==0) fillpoly(7,poly1);

else  if(r2==1) fillpoly(7,poly2);

else  if(r2==2) fillpoly(7,poly3);

else  if(r2==3) fillpoly(7,poly4);


life1=1;

}


}


void audiencepoll()
{
settextstyle(3,0,2); setcolor(BLACK);
outtextxy(30,270,"LIFELINE  TAKEN  ALREADY");
 
1116
1117
1118
1119
1120
1121
1122
1123
1124
1125
1126
1127
1128
1129
1130
1131
1132
1133
1134
1135
1136
1137
1138
1139
1140
1141
1142
1143
1144
1145
1146
1147
1148
1149
1150
1151
1152
1153
1154
1155
1156
1157
1158
1159
1160
1161
1162
1163
1164
1165
1166
1167
1168
1169
1170
1171
1172
1173
1174
1175
1176
1177
1178
1179
1180
1181
1182
1183
1184
1185
1186
1187
1188
1189
1190
1191
1192
1193
1194
1195
1196
1197
1198
1199
1200
1201
1202
 


randomize();
int  r1=0,r2=0,r3=0,r4=0;
if(((button  &1)==1)&&life3==0)
{
hidemouseptr(); setcolor(LIGHTBLUE); settextstyle(0,HORIZ_DIR,2); outtextxy(30,250,"AUDIENCE  POLL  ");
sleep(2);
line();
if(correctans[0]=='a')
{
while(r1<r2||r1<r3||r1<r4||r1+r2+r3+r4!=100)
{
r1=random(100); r2=random(100); r3=random(100); r4=random(100);
}
}
else  if(correctans[0]=='b')
{
while(r2<r1||r2<r3||r2<r4||r1+r2+r3+r4!=100)
{
r1=random(100); r2=random(100); r3=random(100); r4=random(100);
}

}
else  if(correctans[0]=='c')
{
while(r3<r1||r3<r2||r3<r4||r1+r2+r3+r4!=100)
{
r1=random(100); r2=random(100); r3=random(100); r4=random(100);
}
}
else  if(correctans[0]=='d')
{
while(r4<r1||r4<r2||r4<r3||r1+r2+r3+r4!=100)
{
r1=random(100); r2=random(100); r3=random(100); r4=random(100);
}
}

char r11[20];
char r22[20];char r33[20];char r44[20]; itoa(r1,r11,10);
itoa(r2,r22,10);
itoa(r3,r33,10);
itoa(r4,r44,10); setcolor(YELLOW); bar(240,150-r1,260,150); bar(265,150-r2,280,150); bar(285,150-r3,300,150); bar(305,150-r4,320,150);
settextstyle(0,0,1); setcolor(GREEN); outtextxy(240,152,"A     B     C     D"); outtextxy(240,140-r1,r11); outtextxy(265,140-r2,r22); outtextxy(285,140-r3,r33); outtextxy(305,140-r4,r44); setcolor(RED); rectangle(230,30,330,175); life3=1;
f3=1;
setcolor(YELLOW); settextstyle(1,0,2);
outtextxy(0,250,"Press  any  key  on  the  keyboard  to  continue.."); showmouseptr();
getch();
line();

}


}
