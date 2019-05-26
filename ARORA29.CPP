/* project : student data base */
#include<stdio.h>
#include<stdlib.h>  //for atoi() / itoa()
#include<dos.h>
#include<ctype.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#define PASSWORD 1234
struct student
{

    char id[10];
    char name[20];
    char mobile_number[13];
    char fathers_name[20];
    char mothers_name[20] ;
    char address[20];

    char semester[50];

}  ;
typedef struct student std ;


union REGS i , o ;
void loadingAni();
// to check if a string is number of not
int isnum(const char *s)
{
    while (*s)
    {
        if (!isalpha(*s) && !isspace(*s)) return 1;
        *s++;
    }

    return 0;
}
// call mouse
void cm() ;
// mouse position
void mp(int &x , int &y ,int & c  ) ;
void DataBase();
void WelcomePage();
/*
void main()
{

    //DataBase();
    WelcomePage();

}
*/
void main()
{

      //              DataBase();;
    int gd = DETECT , gm ;
    initgraph(&gd,&gm,"c:/tc/bgi");
    int x , y , c  , f = 0;

    while(!kbhit())
    {
		cleardevice();
        settextstyle(10, HORIZ_DIR,1);
        outtextxy(80,30,"Welcome to MBSTU Student DataBase");
        settextstyle(0, HORIZ_DIR, 1);
        rectangle(200,100,400,150);
        //settextstyle(DEFAULT_FONT, DEFAULT_FONT, 1);
        outtextxy(280,120,"Menue");
        rectangle(200,200,400,250);
        outtextxy(280,220,"Close");
        rectangle(200,300,400,350);
	outtextxy(280,320,"About");
	//rectangle(200,400,400,450);
	//outtextxy(280,420,"UPDATE");
	cm();

	while(!kbhit())
	{
			gotoxy(5,5);
			//printf("x = %d y = %d ",x,y);

	    mp(x,y,c);
	    // menue
	    if(c == 1 && x >200 && y >100 && x <400 && y <150)
	    {
				c = 0 ;
				cleardevice();
				delay(200);
				loadingAni();
		DataBase();
				break ;
	    }
	    // close
	    if(c == 1 && x >200 && y >200 && x <400 && y <250)
	    {
	       cleardevice();
	       closegraph();
		return ;
	    }
	    // about
	    if(c == 1 && x >200 && y >300 && x <400 && y <350)
	    {
			cleardevice();
			gotoxy(20,10);
						printf("Project on Student Database By : ") ;
			gotoxy(20,12);
			printf("Sarna Das (IT-15007)");
			gotoxy(20,14);
			printf("Shakera Khandaker (IT-15008)\n");
			getch();
			break ;
	    }

	    //	if(c == 1 && x > && y > && x < && y <){

	    //	}
	}


	}




      //  return ;

    }
void DataBase()
{
    // mouse vars
    int x , y , c ;
    int out = 0 ;
    FILE  *fp ,*fp2, *fp3;
    char file_name[20] ;
    int esc = 0 ;
    int login = 0 ;
    int pass = 0 ;
	int t = 0 ; // temporary variable
	int flag = 0 ;
    // declaring graphics driver
    //and graphics mode
    int gd = DETECT, gm ;
	int need = 0 ;
    // setting the graphics
    initgraph(&gd,&gm,"c:/tc/bgi");
    while(out==0)
    {
	// gui
	// prime buttons
	cleardevice();
	//	setbkcolor(BLACK);
	cm();
	setbkcolor(BLUE);
	setcolor(RED);
	if(login==0)
	{
	    rectangle(10,10,60,30);
	    outtextxy(12,15,"LOGIN");

	}
	else
	{

	    rectangle(10,10,60,30);
	    outtextxy(12,15,"LOG OUT");


	}
	//verride
	/*rectangle(200,50,400,100);
	outtextxy(280,70,"ADD");
	rectangle(200,150,400,200);
	outtextxy(280,170,"SEARCH");
	rectangle(200,250,400,300);
	outtextxy(280,270,"DELETE");
	rectangle(200,350,400,400);
	outtextxy(280,370,"UPDATE");
	*/
	
	 // the title 
	 settextstyle(10, HORIZ_DIR,1);
	//outtextxy(80,30,"Welcome to MBSTU Student DataBase");
	rectangle(200,100,400,150);
	settextstyle(0, HORIZ_DIR, 1);
	//settextstyle(DEFAULT_FONT, DEFAULT_FONT, 1);
	outtextxy(280,120,"ADD");
	rectangle(200,200,400,250);
	outtextxy(280,220,"SEARCH");
	rectangle(200,300,400,350);
	outtextxy(280,320,"DELETE");
	rectangle(200,400,400,450);
	outtextxy(280,420,"UPDATE");

	// exit button
	setfillstyle(SOLID_FILL,RED);
	bar(600,0,650,30);
	textcolor(BLACK);
	outtextxy(605,0,"X");
	
	 /*
	 rectangle(600,10,625,20);
     outtextxy(610,12,"X"); 
	 */
	
	//setcolor(BLACK);
	


	// background
	while(1)
	{
	    mp(x,y,c);
	    //logout
	    if(login==1)
	    {
		if(c==1 && x>=10 && x<=60 && y>=10 && y<=30 )
		{
		    setbkcolor(BLACK);
		    cleardevice();
		    //outtextxy(100,100,"LOGGED_OUT");
		    esc = -1 ;
		    //getch();
		    break ;
		}
	    }
         // dew to unusual error

	    if(esc==-1)
	    {
		esc = 0 ;
		login = 0 ; // logged out
		break ;
	    }
	    // login
	    if(login==0)
	    {


		if(c==1 && x>=10 && x<=60 && y>=10 && y<=30 )
		{

		    setbkcolor(BLACK);
		    clrscr();
		    cleardevice();
		    outtextxy(230,200,"ENTER_PASS_WORD : ");
		    outtextxy(230,240,"_________________________________");
		    gotoxy(30,15);
		    //outtextxy(100,100,"ENTER_PASS_WORD : ");
		    scanf("%d",&pass);
		    if(pass==PASSWORD)
		    {
			cleardevice();
			login = 1 ; // logged in

			outtextxy(230,200,"LOGIN_SUCCESSFUL\n");
			getch();

			break ;
		    }

		    else
		    {
			cleardevice();
			outtextxy(100,100,"WRONG_PASSWORD");
			getch();
			break ;
		    }
		}
	    }

	    //update
	    if(c==1 && x>=200 && x<=400 && y>=400 && y<=450 )
	    {
		setbkcolor(BLACK);
		if(login==0)
		{
		    clrscr();
		    cleardevice();
		    outtextxy(230,200,"You Have To Log In First ");
		    getch();
		    break ;
		}
				file_name[0] = '\0' ;
		delay(30) ;
		cleardevice();
		outtextxy(230,200,"Enter ID to Update : ");
		outtextxy(230,240,"_________________________________");
		gotoxy(30,15);
	    if( gets(file_name))
		flag = 1 ;
		if(!fopen(file_name,"r") && flag==1)
		{
		    clrscr();
		    cleardevice();
		    outtextxy(230,200,"ID_DOES_NOT_EXIST_ON_DATABASE\n");
		    getch();
		    flag = 0 ;
		    break ;
                }
                else
                {
                    clrscr();
                    cleardevice();
                    std temp ;
                    printf("%25sFill up details : \n","");
                    // own name
                    gotoxy(5,5);
                    printf("NAME : ");
                    outtextxy(300,75,"____________________");

                    // gotoxy(13,5);
                    // scanf("%s",ch[20]);
                    gotoxy(5,8);
                    printf("Father`s Name : ");
                    outtextxy(300,125,"____________________");
                    // scanf("%s",ch[20]);
                    gotoxy(5,11);
                    printf("Mother`s Name :");
                    outtextxy(300,170,"____________________");
                    gotoxy(5,14);
                    printf("Mobile Number :");
                    outtextxy(300,220,"____________________");
                    gotoxy(5,17);
                    printf("Address : ");
                    outtextxy(300,270,"____________________");
                    gotoxy(5,20);
                    printf("Current Semester :");
                    outtextxy(300,320,"____________________");

                    // scanning part
                    // name
                    gotoxy(40,5);
                    //  gets(file_name); // for none logic not found
                    gets(temp.name);
					while(isnum(temp.name) || strlen(temp.name)<=3 ){ // if string is empty or string is only number will have to enter again
					    gotoxy(40,5);
						if( strlen(temp.name)<=3){
							 printf("Too Shorrt ");
						}else{
						  printf("Enter charecter only ");
						}

						getch();
						gotoxy(40,5);
						printf("                       ");
						gotoxy(40,5);

						gets(temp.name);
					}
					// if input is number then
                    strcat(temp.name,"\n");
                    // changing colout if pressed enter
                    setcolor(GREEN);
                    outtextxy(300,75,"____________________");
                    // faters name
                    gotoxy(40,8);
                    gets(temp.fathers_name);
						while(isnum(temp.fathers_name) || strlen(temp.fathers_name)<=3 ){ // if string is empty or string is only number will have to enter again
					    gotoxy(40,8);
						if( strlen(temp.fathers_name)<=3){
							 printf("Too Shorrt ");
						}else{
						  printf("Enter charecter only ");
						}

						getch();
						gotoxy(40,8);
						printf("                       ");
						gotoxy(40,8);

						gets(temp.fathers_name);
					}
                    strcat(temp.fathers_name,"\n");
                    setcolor(GREEN);
                    outtextxy(300,125,"___________________");
                    // mothers_name
                    gotoxy(40,11);
                    gets(temp.mothers_name);
						while(isnum(temp.mothers_name) || strlen(temp.mothers_name)<=3 ){ // if string is empty or string is only number will have to enter again
					    gotoxy(40,11);
						if( strlen(temp.mothers_name)<=3){
							 printf("Too Shorrt ");
						}else{
						  printf("Enter charecter only ");
						}

						getch();
						gotoxy(40,11);
						printf("                       ");
						gotoxy(40,11);

						gets(temp.mothers_name);
					}
                    strcat(temp.mothers_name,"\n");
                    setcolor(GREEN);
                    outtextxy(300,170,"___________________");
                    //mobile_number
                    gotoxy(40,14);
                    gets(temp.mobile_number);
					// in case mobile number is too short
					while(1){

                         if(isnum(temp.mobile_number) && strlen(temp.mobile_number)==11){
							 break ;
						 }else{

							 gotoxy(40,14);
							 printf("Has To Be 11 Digits");
							 getch();
							 gotoxy(40,14);
							 printf("                     ");
							 gotoxy(40,14);
							 gets(temp.mobile_number);
						 }
					}
                    strcat(temp.mobile_number,"\n");
                    setcolor(GREEN);
                    outtextxy(300,220,"___________________");
                    // address
                    gotoxy(40,17);
                    gets(temp.address);
                    strcat(temp.address,"\n");
                    setcolor(GREEN);
                    outtextxy(300,270,"____________________");
                    //semestr
                    gotoxy(40,20);
                    gets(temp.semester);
                    strcat(temp.semester,"\n");
                    setcolor(GREEN);
                    outtextxy(300,320,"____________________");
                    // writing the collected data to file
                    //	strcat(file_name);
                    fp = fopen(file_name,"w");
					fprintf(fp,temp.id);
                    fprintf(fp,temp.name);
                    fprintf(fp,temp.fathers_name);
                    fprintf(fp,temp.mothers_name);
                    fprintf(fp,temp.mobile_number);
                    fprintf(fp,temp.address);
                    fprintf(fp,temp.semester);
                    gotoxy(40,25);
                    printf("PRESS_ENTER_TO_SAVE");
                    getch();
                    fclose(fp) ;
                    break ;


                }
            }
            //delete button
            if(c==1 && x>=200 && x<=400 && y>=300 && y<=350 && login==0) // exeption not logged in
            {
                clrscr();
                cleardevice();
                setbkcolor(BLACK);
                outtextxy(230,200,"Log In To Delet \n");
                getch();
                break ;
            }
            else if(c==1 && x>=200 && x<=400 && y>=300 && y<=350 && login==1)
            {

				cleardevice() ;
				delay(200);

                setbkcolor(BLACK);

                cleardevice();
				file_name[0] = '\0' ;
				delay(30) ;
                outtextxy(230,200,"Enter ID to Delet : ");
                outtextxy(230,240,"_________________________________");
                gotoxy(30,15);
				flag = 0 ;
		        if(gets(file_name)) flag = 1 ;
				// if file is open

                if(fopen(file_name,"r") && flag ==1 )
                {
                    // removing the file from DATABASE_DIRECTORY
                    cleardevice();

					std tempo ; // temporary structure
					char tem[100] ;// temporary string
					fp = fopen(file_name,"r");
					fscanf(fp,"%s\n",tem); // id
					fscanf(fp,"%s\n",tem); // name
					fscanf(fp,"%[^\n]\n",tem); // fathers name
					//printf("%s\n",tem);
					fclose(fp);
		    outtextxy(230,200,"REMOVING_FILE_PLEASE_WAIT....\n");
		    delay(5000);

		    remove(file_name);
					remove(tem); // fathers name file removed
                    cleardevice();
                    outtextxy(230,200,"DATA_HAS_BEEN_FORMATTED\n");
                    getch();
                    break ;
				     //	flag = 0 ;
                }
                else // file is not open
                {
					cleardevice();
                    outtextxy(230,200,"ID_DOES_NOT_EXIST_ON_DATABASE\n");
					if(need==0){
						need = 1 ;
					}else
                    getch();
                    break ;

                }

            }


            // search button
            if(c==1 && x>=200 && x<=400 && y>=200 && y<=250 )
            {
                setbkcolor(BLACK);
                clrscr();
                cleardevice();
                outtextxy(230,200,"Enter ID to Search : ");
                outtextxy(230,240,"_________________________________");
                   gotoxy(30,15);
                gets(file_name);	
                //scanf("%s",file_name);
                if(fopen(file_name,"r")==0)
                {
                    gotoxy(5,5);
                    clrscr();
                    cleardevice();
                    outtextxy(30,15,"NO_ENTRY_FOUND_IN_DATABASE\n");
                    getch();
                    break ;
                }
                else
                {
                    cleardevice();
                    fp = fopen(file_name,"r");
                    char t[20] ;
					fgets(t,10,fp);
					
  					gotoxy(5,2);
					printf("ID : -   %s \n",t);
                    gotoxy(5,5);
                    printf("NAME : ");
                    outtextxy(300,75,"____________________");
                    // gotoxy(13,5);
                    // scanf("%s",ch[20]);
                    gotoxy(5,8);
                    printf("Father`s Name : ");
                    outtextxy(300,125,"____________________");
                    // scanf("%s",ch[20]);
                    gotoxy(5,11);
                    printf("Mother`s Name :");
                    outtextxy(300,170,"____________________");
                    gotoxy(5,14);
                    printf("Mobile Number :");
                    outtextxy(300,220,"____________________");
                    gotoxy(5,17);
                    printf("Address : ");
                    outtextxy(300,270,"____________________");
                    gotoxy(5,20);
                    printf("Current Semester :");
                    outtextxy(300,320,"____________________");
////

                    // name
                    gotoxy(40,5);
                    fgets(t,20,fp);
                    printf("%s",t);


                    // faters name
                    gotoxy(40,8);
                    fgets(t,20,fp);
                    printf("%s",t);

                    // mothers_name
                    gotoxy(40,11);
                    fgets(t,20,fp);
                    printf("%s",t);

                    //mobile_number
                    gotoxy(40,14);
                    fgets(t,20,fp);
                    printf("%s",t);

                    // address
                    gotoxy(40,17);
                    fgets(t,20,fp);
                    printf("%s",t);

                    //semestr
                    gotoxy(40,20);
                    fgets(t,20,fp);
                    printf("%s",t);

                    getch();
                    break ;
                }
            }

            // add button
            if(c==1 && x>=200 && x<=400 && y>=100 && y<=150 )
            {

                //clrscr();
                cleardevice();
                setbkcolor(BLACK);
                std temp ;
                outtextxy(230,200,"Enter ID to Add : ");
                outtextxy(230,240,"_________________________________");

                gotoxy(30,15);
                //scanf("%s",temp.id);
                gets(temp.id);
				while(strlen(temp.id)<4){
					gotoxy(30,15);
					printf("Invalid!!!");
					getch();
					gotoxy(30,15);
					printf("                            ");
					gotoxy(30,15);
					gets(temp.id);
				}
				char t[20];
				//t[0] = '\0' ;
				strcpy(t,temp.id);
				strcat(temp.id,"\n");
                // id will be considered as file name hear
                // scanf("%s",file_name); // file name is student id hear
                //fp = fopen(temp.id,"w");
                clrscr();
                cleardevice();
                if(fopen(t,"r")!=0) // previously exists
                {
                    cleardevice();
                    outtextxy(230,200,"ID Already Exists\n");
                    getch();
                    break ;

                }
                else
                {
                    printf("%25sFill up details : \n","");
                    // own name
                    gotoxy(5,5);
                    printf("NAME : ");
                    outtextxy(300,75,"____________________");

                    gotoxy(5,8);
                    printf("Father`s Name : ");
                    outtextxy(300,125,"____________________");

                    gotoxy(5,11);
                    printf("Mother`s Name :");
                    outtextxy(300,170,"____________________");
                    gotoxy(5,14);
                    printf("Mobile Number :");
                    outtextxy(300,220,"____________________");
                    gotoxy(5,17);
                    printf("Address : ");
                    outtextxy(300,270,"____________________");
                    gotoxy(5,20);
                    printf("Current Semester :");
                    outtextxy(300,320,"____________________");

                    // scanning part
                    // name
                    gotoxy(40,5);
                    //gets(file_name); // for none logic not found
                    gets(temp.name);

					while(isnum(temp.name) || strlen(temp.name)<=3 ){ // if string is empty or string is only number will have to enter again
					    gotoxy(40,5);
						if( strlen(temp.name)<=3){
							 printf("Too Shorrt ");
						}else{
						  printf("Enter charecter only ");
						}

						getch();
						gotoxy(40,5);
						printf("                       ");
						gotoxy(40,5);

						gets(temp.name);
					}
                    strcat(temp.name,"\n");
                    // changing colout if pressed enter
                    setcolor(GREEN);
                    outtextxy(300,75,"____________________");
                    // faters name
                    gotoxy(40,8);
                    gets(temp.fathers_name);
						while(isnum(temp.fathers_name) || strlen(temp.fathers_name)<=3 ){ // if string is empty or string is only number will have to enter again
					    gotoxy(40,8);
						if( strlen(temp.fathers_name)<=3){
							 printf("Too Shorrt ");
						}else{
						  printf("Enter charecter only ");
						}

						getch();
						gotoxy(40,8);
						printf("                       ");
						gotoxy(40,8);

						gets(temp.fathers_name);
					}
                    strcat(temp.fathers_name,"\n");
                    setcolor(GREEN);
                    outtextxy(300,125,"___________________");
                    // mothers_name
                    gotoxy(40,11);
                    gets(temp.mothers_name);

						while(isnum(temp.mothers_name) || strlen(temp.mothers_name)<=3 ){ // if string is empty or string is only number will have to enter again
					    gotoxy(40,11);
						if( strlen(temp.mothers_name)<=3){
							 printf("Too Shorrt ");
						}else{
						  printf("Enter charecter only ");
						}

						getch();
						gotoxy(40,11);
						printf("                       ");
						gotoxy(40,11);

						gets(temp.mothers_name);
					}

                    strcat(temp.mothers_name,"\n");
                    setcolor(GREEN);
                    outtextxy(300,170,"___________________");
                    //mobile_number
                    gotoxy(40,14);
                    gets(temp.mobile_number);
					// in case mobile number is too short
					while(1){

                         if(isnum(temp.mobile_number) && strlen(temp.mobile_number)==11){
							 break ;
						 }else{

							 gotoxy(40,14);
							 printf("Has To Be 11 Digits");
							 gotoxy(40,14);
							 getch();
							 gotoxy(40,14);
							 printf("                      ");
							 gotoxy(40,14);
							 gets(temp.mobile_number);
						 }
					}
                    strcat(temp.mobile_number,"\n");
                    setcolor(GREEN);
                    outtextxy(300,220,"___________________");
                    // address
                    gotoxy(40,17);
					gets(temp.address);
                    while(strlen(temp.address)<=4){
						gotoxy(40,17);
						printf("                             ");
						getch();
						gotoxy(40,17);
						gets(temp.address) ;
					}
                    strcat(temp.address,"\n");
                    setcolor(GREEN);
                    outtextxy(300,270,"____________________");
                    //semestr
                    gotoxy(40,20);

					while(1){
				      gotoxy(40,20);
                      gets(temp.semester);
					  if(atoi(temp.semester)>0 && atoi(temp.semester)<=8){

						     break ;
				      }else{

						  gotoxy(40,20);
						  printf("Invalid !!");
						  getch();
						  gotoxy(40,20);
						  printf("                ");


					  }

					}
                    strcat(temp.semester,"\n");
                    setcolor(GREEN);
                    outtextxy(300,320,"____________________");
                    // writing the collected data to file
                    //	strcat(file_name);
					// as id file
					
					
                    fp = fopen(t,"w");
                    fprintf(fp,temp.id);
                    fprintf(fp,temp.name);
                    fprintf(fp,temp.fathers_name);
                    fprintf(fp,temp.mothers_name);
                    fprintf(fp,temp.mobile_number);
                    fprintf(fp,temp.address);
                    fprintf(fp,temp.semester);
					fclose(fp) ;
					// append mode

					// as fathers name
					char t2[100] ;
					strcpy(t2,temp.fathers_name);
					t2[strlen(temp.fathers_name)-1] = '\0';
					 fp3 = fopen(t2,"w");

					//fprintf(fp,temp.id) ;
					fprintf(fp3,temp.id);
  				    fprintf(fp3,temp.name);
                    fprintf(fp3,temp.fathers_name);
                    fprintf(fp3,temp.mothers_name);
                    fprintf(fp3,temp.mobile_number);
                    fprintf(fp3,temp.address);
                    fprintf(fp3,temp.semester);
					fclose(fp3) ;
					// as fathers name
				
					 /*
					// as name
					fp = fopen(temp.name,"a+");
				    fprintf(fp,"\n\n");
					fprintf(fp,temp.id) ;
  				    fprintf(fp,temp.name);
                    fprintf(fp,temp.fathers_name);
                    fprintf(fp,temp.mothers_name);
                    fprintf(fp,temp.mobile_number);
                    fprintf(fp,temp.address);
                    fprintf(fp,temp.semester);
					fclose(fp) ;
					// end
					*/
                    gotoxy(40,25);
                    printf("PRESS_ENTER_TO_SAVE");
                    getch();

                    break ;
                }
            }



            //exit button
            /*if(c == 1 && x>600 && y>10 && x<625 && y<20) {
		   cleardevice();
		    delay(100);
		    return ;
	       }
		   */
			if(c==1 && x>=600 && x<=650 && y>=0 && y<=30 )
            {
                out = -1 ;
                break ;
            } 

        }


    }
    //	background

}



 void cm()
        {
            i.x.ax = 1 ;
            int86(0x33,&i,&o);
        }
        void mp(int &x ,int &y ,int &c )
        {
            i.x.ax = 3 ;
            int86(0x33,&i,&o);

            c = o.x.bx ;
            x = o.x.cx ;
            y = o.x.dx ;
        }
		
		void loadingAni()
{
 int x,y,i;
 int g=DETECT, d;
 initgraph(&g, &d,"C:\\TC\\BGI");
 cleardevice();
 x=getmaxx()/2;
 y=getmaxy()/2;
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 setbkcolor(rand());
 setcolor(4);
 int c=150;
for(int e=0;e<15;e++)
 {
  for(int i=50;i<100;i++)
  {
   settextstyle(SMALL_FONT, HORIZ_DIR, 10);
   outtextxy(x,y,"Loading...");
      settextstyle(SMALL_FONT, HORIZ_DIR, 5);
   outtextxy(x+5,y+5,"project.. ");
   setcolor(3);
   circle(x,y,i);
   circle(x,y,c);
   c--;
   cleardevice();
  }
  }
  setcolor(6);
 closegraph();
 }

