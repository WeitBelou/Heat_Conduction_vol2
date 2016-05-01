#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>

class Vertex;

class Edge : public QGraphicsItem
{
public:
	Edge(Vertex *sourceNode, Vertex *destNode, double m_u);

	Vertex *sourceNode() const;
	Vertex *destNode() const;

	void adjust();

	enum { Type = UserType + 2 };
    int type() const Q_DECL_OVERRIDE { return Type; };
    QPainterPath shape() const override;

	double u() const;

	QPointF sourcePoint() const;

	QPointF destPoint() const;

protected:
	QRectF boundingRect() const Q_DECL_OVERRIDE;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

private:
	Vertex *source, *dest;

	QPointF m_sourcePoint;
	QPointF m_destPoint;

	double m_u;
};

#endif // EDGE_H