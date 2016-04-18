#ifndef PLOTTINGWIDGET_H
#define PLOTTINGWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <qcustomplot.h>
#include "../core/layer.h"

class PlottingWidget : public QWidget
{
	Q_OBJECT
public:
	explicit PlottingWidget(QWidget *parent = 0);

	void setCurrentIndex(const int &currentIndex);
	int currentIndex() const;

public slots:
	void setData(const QVector<Layer> &data);
	void replot();

private slots:
	void drawCurrentLayer();

private:
	void configurePlot();

	QCustomPlot * plot;
	QCPColorMap * colorMap;
	QCPColorScale * colorScale;
	QCPMarginGroup * marginGroup;

	QHBoxLayout * l;

	QVector<Layer> m_data;
	int m_currentIndex;

	QTimer * loop;
};

#endif // PLOTTINGWIDGET_H