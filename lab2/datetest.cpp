// projektlokala headerfiler
#include "kattistime.h"     
#include "julian.h"         
#include "gregorian.h"      
#include "calendar.h"
// STL headerfiler
#include <iostream>
#include <stdexcept>
#include <assert.h>             // assert(b) ger felmeddelande om b falsk
#include <ctime>
#include <sstream>


// Obs att testerna förutsätter att dina klasser returnerar
// månader och dagar indexerade från ETT. Testerna är inte
// fullständiga


int main()
{
    using namespace lab2;        // Exponera funktionalitet i namnrymden lab2

    ////////////////////////////////////////////////////////////
    // Sätt tiden. OBS skicka inte nedanstående kod till kattis
    time_t mytime;
    time(&mytime);
    set_k_time(mytime);
    ////////////////////////////////////////////////////////////

	
	
	
	
	
	{
		cout << "testing constructors" << endl;
		try {
			Julian J(2012,-1,1);
			assert(false);
		} catch(std::out_of_range) {}

		try {
			Gregorian g(2012,1,-1);
			assert(false);
		} catch(std::out_of_range) {}
		
		try {
			Julian J(2012,1,-1);
			assert(false);
		} catch(std::out_of_range) {}

		try {
			Gregorian g(2012,-1,1);
			assert(false);
		} catch(std::out_of_range) {}
		
		try {
			Julian J(-2012,1,1);
		} catch(std::out_of_range) {
			assert(false);
		}

		try {
			Gregorian g(-2012,1,1);
		} catch(std::out_of_range) {
			assert(false);
		}
		
		Gregorian b1(1858,1,1);
		assert(b1.week_day() == 5); // ska vara en fredag
		Julian j1(1858,1,1);
		assert(j1.week_day() == 3);
		
		Julian today,j;
		Gregorian todayg, bday(1990, 1, 25);
		std::cout << "idag är det " << today << " enligt julianska kalendern" << std::endl;
		std::cout << "idag är det " << todayg << " enligt gregorianska kalendern" << std::endl;
		
		cout << "testing weekday names" << endl;
		j = Julian();
		Gregorian a;
		cout << j << " " << a << endl;
		for(int i = 0; i < 40; ++i){
			j++;a++;
		}

		a = Gregorian(2000,2,29);
		Gregorian b(2000, 1, 31);

		a.add_month();
		b.add_month();
		assert(a.day() == 29);
		assert(a.month() == 3);
		assert(b.day() == 1);
		assert(b.month() == 3);


		a = Gregorian(2005, 5, 30);
		b = a;
		b.add_year(37);
		for (int i = 0; i < 37; ++i) {
			a.add_year();
		}
		assert(a == b);

		try {
			b = Gregorian(2001, 2, 29);
			assert(false);
		} catch (std::out_of_range) { }

		try {
			b = Gregorian(1900, 2, 29);
			assert(false);
		} catch (std::out_of_range) { }
		b = Gregorian(1900, 2, 1);
		assert(b.days_this_month() == 28);

		a = Gregorian(2000, 1, 20);
		assert((a++).day() == 20);
		assert(a.day() == 21);
		assert((++a).day() == 22);

		a = Gregorian(2000, 1, 20);
		j = a;
		
		assert((a - j) == 0);
		assert(a == j && j == a);

		j++;
		assert(j > a);

		j--;
		a++;
		assert(j < a);

		Julian jul(2196, 2, 1);
		assert(jul.days_this_month() == 29);
		jul.add_month();
		assert(jul.days_this_month() == 31);

		b = Gregorian(2000, 2, 1);
		assert(b.days_this_month() == 29);

		j = Julian(1993, 3, 29);
		Julian foo = j;
		foo.add_month(-1);
		int diff = j - foo;
		assert(diff == 30);

		j = Julian(1987, 1, 13);
		j.add_month(-1);
		assert(j.day() == 13);
		assert(j.month() == 12);
		assert(j.year() == 1986);

		j = Julian(1992, 3, 29);
		foo = j;
		j.add_month(-1);
		assert(foo - j == 29);

		j = Julian(2012, 7, 31);
		foo = j;
		j.add_month(-1);
		assert(foo - j == 30);

		j = Julian(2012, 6, 30);
		j.add_month(-1);
		assert(j.day() == 30);
		assert(j.month() == 5);
		assert(j.year() == 2012);

		j = Julian(1992, 2, 29);
		j.add_month(-28);
		assert(j.year() == 1989);
		assert(j.month() == 10);
		assert(j.day() == 27);

		j = Julian(1991, 1, 29);
		foo = j;
		j.add_month();
		diff = j - foo;
		assert(j - foo == 30);

		// Nästa kattis-tests:

		j = Julian(1992, 2, 29);
		j.add_month(-28);
		j.add_month(0);
		j.add_month(14);
		j.add_month(0);
		j.add_month(43);
		j.add_month(0);
		j.add_month(-43);
		assert(j.year() == 1990 &&
			j.month() == 12 &&
			j.day() == 27);
	}
	
	cout << "testing add_year" << endl;
	Julian j2(2000,2,29);
	Gregorian g2(2000,2,29);
	j2.add_year(-4);
	g2.add_year(-4);
	assert(j2.day()==29);
	assert(j2.year()==1996);
	j2.add_year(-8);
	j2.add_year(7);
	assert(g2.day()==29);
	assert(g2.year()==1996);
	g2.add_year(-8);
	g2.add_year(7);
	assert(j2.day()==28);
	assert(j2.year()==1995);
	assert(g2.day()==28);
	assert(g2.year()==1995);
	j2.add_year(-137);
	assert(j2.year() == 1858);
	j2.add_year(700);
	assert(j2.year() == 2558);
	g2.add_year(-137);
	assert(g2.year() == 1858);
	g2.add_year(700);
	assert(g2.year() == 2558);


	{

		/* Calendar tests. */
		Calendar<Gregorian> hogtider;
		Calendar<Gregorian> j2;
		/* Invalid events (dates actually) */
		assert(hogtider.set_date(2001, 2, 29) == false);
		assert(hogtider.add_event("skottdag", 29, 2, 2001) == false);
		assert(hogtider.remove_event("skottdag", 29, 2, 2001) == false);

		/* Ordering */
		hogtider.set_date(2012, 12, 1);
		hogtider.add_event("forsta rutan i chokladkalendern");
		hogtider.add_event("lunch", 24);
		hogtider.add_event("kalle anka", 24, 12);
		hogtider.add_event("Halloween", 30, 10, 2012);
		hogtider.add_event("jultomten", 24, 12);
		hogtider.add_event("julbord", 25, 12);
		assert(false == hogtider.add_event("jultomten", 24, 12));

		assert(true == hogtider.remove_event("jultomten", 24, 12));
		assert(true == hogtider.add_event("jultomten", 24, 12));

		cout << "SKRIVER UT KALENDERN" << endl; 
		ostringstream ss;
		cout << hogtider << endl;
		ss << hogtider << endl;
		assert(string("2012-12-24 : lunch\n2012-12-24 : kalle anka\n2012-12-24 : jultomten\n2012-12-25 : julbord\n\n") == ss.str());
		Calendar<Gregorian> ab = Calendar<Gregorian>();
		Calendar<Gregorian> ac(hogtider);
		Calendar<Gregorian> ad = hogtider;
		Calendar<Julian> andra_tider;
		andra_tider = hogtider;
		j2 = hogtider;
		//End calender tests
	}

    Julian tj;                  // ok: defaultkonstruktor ger dagens datum
    Gregorian gtoday;           // ok för gregorian också
    std::cout << "Idag är det " << gtoday << std::endl;
    assert(tj - gtoday == 0);
    Gregorian tg(2006, 10, 31); // ok: sätt datum explicit
                                // följande fungerar också:
                                // Gregorian(2000, Gregorian::October, 31)
    Date &j = tj;               // åtkomst av funktioner genom Dates interface
    Date &g = tg;       
    Date &today = gtoday;

    {
      Julian j1;
      Date & d1 = j1;
      Julian j2(d1);
      Date * dp = &j2;
      Julian j3(dp);
    }
     
    time_t tp;
    time(&tp);
    struct tm *t = gmtime(&tp);
    int year  = t->tm_year + 1900;
    int month = t->tm_mon + 1;      // månaderna och dagarna
    int day   = t->tm_mday;         // indexerade från ETT

    std::cout << "Testing constructors..." << std::endl;
    assert(today.year() == year &&          // rätt initierad
           today.month() == month &&
           today.day() == day);
    assert(g.year() == 2006 &&              // rätt initierad
           g.month() == 10 &&
           g.day() == 31);                  // obs! ettindexerade
    
    std::cout << "Testing access..." << std::endl;
    assert(g.days_per_week() == 7);         // rätt antal dagar per vecka
    assert(j.days_per_week() == 7);         // rätt antal dagar per vecka
    assert(g.days_this_month() == 31);      // rätt antal dagar denna månad
    assert(g.months_per_year() == 12);      // rätt antal månader per år
    assert(j.months_per_year() == 12);      // rätt antal månader per år
    assert(g.week_day() == 2); // rätt veckodag

    std::cout << "Testing manipulation..." << std::endl;
    ++g;                                    // prefix ökning
    assert(g.week_day() == 3); // rätt veckodag
    --g;                                    // prefix minskning
    assert(g.week_day() == 2); // rätt veckodag
    g += 2;                                 // lägg till två dagar
    assert(g.week_day() == 4); // rätt veckodag
    g -= 3;                     // dra bort tre dagar
    g.add_month();              // lägg till en månad
    g.add_month(-1);            // dra bort en månad    
    g.add_year(10);             // lägg till tio år.
    
    std::cout << "Testing miscellaneous functions..." << std::endl;
    Julian jj(tj);              // kopieringskonstruktor
    const Gregorian gg;
    gg.year();                  // gg konstant, läsa går bra
    g = gg;                     // tilldelning
    if(g == gg ||               // jämförelse
       g != gg ||               // jämförelse 
       g < gg ||                // jämförelse 
       g >= gg)                 // jämförelse 
        {}
    
    std::cout << "Testing boundary violations";
    Gregorian temp(1900, 1, 1);
    Date &d = temp;

    // loopa över dagar och kolla att inga gränser över/underskrids
    for(int i = 0; i < 100000; ++i, ++d)
        {
            if(!(i % 5000))        // utskrift på framsteg
                {
                    std::cout << ".";
                    flush(std::cout);
                }
            int m[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if(d.year() >= 1900 && 
               d.month() >= 1 && d.month() <= 12 &&
               d.day() >= 1 && d.day() <= m[d.month() - 1])
                {}
            else
                {
                    std::cout << std::endl;
                    std::cout << "boundary checks failed: " << std::endl;
                    std::cout << d.year() << ", "
                              << d.month() << ", "
                              << d.day() << std::endl;
                    return 1;
                }
        }
    std::cout << std::endl;

    std::cout << "Testing leap years..." << std::endl;
    // testa om skottåren för sekelskiften fungerar som de ska
    for(int y = 1958; y < 2500; y += 100)
        {
            Gregorian temp(y, 2, 28);
            Date &e = temp;
            ++e;                                   // lägg till en dag
            if((y % 400 == 0 && e.day() == 29) ||  // skottdag (obs! ETTindexerad)
               (y % 400 != 0 && e.day() == 1))     // ej skottdag
                {}
            else
                {
                    std::cout << std::endl << "leap day test failed: " << std::endl;
                    std::cout << e.year() << ", "
                              << e.month() << ", "
                              << e.day() << std::endl;
                    return 1;
                }
        }
	Julian j3(2319,1,7);
	int JDN_1 = j3.mod_julian_day();
	cout << "j3: " << j3.mod_julian_day() << " " << j3 <<  endl;
	Gregorian g3;
	cout << "g3: " << g3.mod_julian_day() << " " << g3 <<  endl;
	g3 = j3;
	cout << "j3: " << j3.mod_julian_day() << " " << j3 <<  endl;
	cout << "g3: " << g3.mod_julian_day() << " " << g3 <<  endl;
	assert(g3 == j3);
	assert(j3.mod_julian_day() == JDN_1);
	assert(g3.mod_julian_day() == JDN_1);
	    
    std::cout << std::endl << "All tests were successful." << std::endl;

    // följande ska inte gå att kompilera
#if 0
    gg.leap_year();             // fel: kan inte komma åt protected/private medlem
    gg = g;                     // fel: kan inte tilldela konstant
    ++gg;                       // fel: kan inte ändra på en konstant
#endif

    return 0;
}

