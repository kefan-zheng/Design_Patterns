#include "Composite.h"

int testComposite() {
	CompositeEvents* overallEvents=new CompositeEvents("总体活动");
	CompositeEvents* swimming=new CompositeEvents("游泳");
	CompositeEvents* running = new CompositeEvents("跑步");

	overallEvents->add(swimming);
	overallEvents->add(running);

	swimming->add(new SingleEvents("男子50米蛙泳", "2021-10-19 14:00", "1号游泳馆"));
	swimming->add(new SingleEvents("女子50米自由泳", "2021-10-20 15:00", "1号游泳馆"));
	swimming->add(new SingleEvents("男子100米蝶泳", "2021-10-18 10:00", "3号游泳馆"));
	running->add(new SingleEvents("男子100米赛跑", "2021-10-17 10:30", "1号田径场"));
	running->add(new SingleEvents("女子1000米赛跑", "2021-10-20 14:30", "2号田径场"));
	overallEvents->show();

	cout << endl;

	return 0;
}