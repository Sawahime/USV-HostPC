# USV-HostPC
无人船上位机

GIF：测试视频

USVGCS：上位机软件工程
	仿真：	点击“建立连接”
			点击“设置原点”
			点击“设置终点”
			点击“仿真初始化”
			点击“发送指令”

	绘图：	点击“Start”开始绘图
	 		点击“Clear”清除已绘制的图线
			点击“X-Y”“航速”“航向”“速度”“转向”切换图像

	回放：	点击“导入csv文件”
			点击“回放”

	电子围栏：利用地图右上角的工具绘制即可

	需要修改的地方：	“mainwindow.h”中的私有成员“mapPath”
			“mainwindow.cpp”中的:on_pushButton_simulatorInit_clicked()函数中的“csv_name”

USVSIM：仿真虚拟无人船

Visio：	类图
		程序流程图
		软件功能图
