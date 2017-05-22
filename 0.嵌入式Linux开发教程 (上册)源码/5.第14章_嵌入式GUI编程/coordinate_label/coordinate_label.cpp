/* coordinate_label.cpp */

#include <QMouseEvent>
#include "coordinate_label.h"

void CoordinateLabel::mousePressEvent(QMouseEvent *event)
{
	this->setText(QString("Mouse Press at:[%1, %2]")
					.arg(event->x())
					.arg(event->y()));
}

void CoordinateLabel::mouseMoveEvent(QMouseEvent *event)
{
	this->setText(QString("Mouse Move at:[%1, %2]")
					.arg (event->x())
					.arg(event->y()));
}

void CoordinateLabel::mouseReleaseEvent(QMouseEvent *event)
{
	this->setText(QString("Mouse Release at:[%1, %2]")
					.arg (event->x())
					.arg (event->y()));
}

