#include "Composite.h"
int testComposite() {
	//第一层，为复合比赛
	CompositeEvents* overallEvents=new CompositeEvents("Olympics");
	//第二层，均为复合比赛
	CompositeEvents* swimming=new CompositeEvents("Swimming");
	CompositeEvents* running = new CompositeEvents("Running");
	CompositeEvents* tableTennis = new CompositeEvents("Table Tennis");
	CompositeEvents* badminton = new CompositeEvents("Badminton");
	overallEvents->add(swimming);
	overallEvents->add(running);
	overallEvents->add(tableTennis);
	overallEvents->add(badminton);
	//第三层，均为单个比赛
	swimming->add(new SingleEvents("Men's 100m freestyle", "2021-07-23 08:00:00", "Swimming pool"));
	swimming->add(new SingleEvents("Women's 100m freestyle", "2021-07-24 08:00:00", "Swimming pool"));
	swimming->add(new SingleEvents("Men's 100m breaststroke", "2021-07-22 09:20:00", "Swimming pool"));
	swimming->add(new SingleEvents("Women's 100m breaststroke", "2021-07-23 14:40:00", "Swimming pool"));
	running->add(new SingleEvents("Men's 100m run", "2021-07-25 10:20:00", "Running field"));
	running->add(new SingleEvents("Women's 100m run", "2021-07-26 09:30:00", "Running field"));
	running->add(new SingleEvents("Men's 2000m run", "2021-07-23 08:20:00", "Running field"));
	running->add(new SingleEvents("Women's 2000m run", "2021-07-27 08:45:00", "Running field"));
	tableTennis->add(new SingleEvents("Men's semifinal", "2021-07-17 20:30:00", "Table Tennis room"));
	tableTennis->add(new SingleEvents("Women's semifinal", "2021-07-20 20:30:00", "Table Tennis room"));
	tableTennis->add(new SingleEvents("Men's final", "2021-07-25 20:30:00", "Table Tennis room"));
	tableTennis->add(new SingleEvents("Women's final", "2021-07-23 20:30:00", "Table Tennis room"));
	badminton->add(new SingleEvents("Men's final", "2021-07-30 21:30:00", "Badminton room"));
	badminton->add(new SingleEvents("Women's final", "2021-07-27 21:30:00", "Badminton room"));
	//展示
	overallEvents->show();
	cout << "After the removal of swimming: \n\n";
	overallEvents->remove(swimming,overallEvents);
	overallEvents->show();
	return 0;
}