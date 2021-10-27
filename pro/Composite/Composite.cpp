#include "Composite.h"

int testComposite() {
	CompositeEvents* overallEvents=new CompositeEvents("����");
	CompositeEvents* swimming=new CompositeEvents("��Ӿ");
	CompositeEvents* running = new CompositeEvents("�ܲ�");

	overallEvents->add(swimming);
	overallEvents->add(running);

	swimming->add(new SingleEvents("����50����Ӿ", "2021-10-19 14:00", "1����Ӿ��"));
	swimming->add(new SingleEvents("Ů��50������Ӿ", "2021-10-20 15:00", "1����Ӿ��"));
	swimming->add(new SingleEvents("����100�׵�Ӿ", "2021-10-18 10:00", "3����Ӿ��"));
	running->add(new SingleEvents("����100������", "2021-10-17 10:30", "1���ﾶ��"));
	running->add(new SingleEvents("Ů��1000������", "2021-10-20 14:30", "2���ﾶ��"));
	overallEvents->show();

	cout << endl;

	return 0;
}