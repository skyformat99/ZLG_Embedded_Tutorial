/* coordinate_label.h */

#ifndef COORDINATE_LABEL_H
#define COORDINATE_LABEL_H

#include <QLabel>

class QMouseEvent;

class CoordinateLabel : public QLabel						/* 自定义Qlabel的子类 */
{
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};

#endif

