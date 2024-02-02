#ifndef ZOOMWIDGET_H
#define ZOOMWIDGET_H

#include <QWidget>

class ZoomWidget : public QWidget
{
    Q_OBJECT

public:
    ZoomWidget(QWidget *parent = nullptr);
    ~ZoomWidget();
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    QPointF m_camPos {0., 0.};
    qreal m_scale {1.0};
    bool m_mousePressed {false};
    QPoint m_mousePrevPos;
};
#endif // ZOOMWIDGET_H
