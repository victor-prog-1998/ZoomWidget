#include "zoomwidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>

ZoomWidget::ZoomWidget(QWidget *parent)
    : QWidget(parent)
{
}

ZoomWidget::~ZoomWidget()
{
}

void ZoomWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    int w = 100 * m_scale;
    int h = 60 * m_scale;

    painter.translate(-m_camPos * m_scale);
    painter.setBrush(Qt::green);
    painter.drawRect(0, 0, w, h);
    painter.setBrush(Qt::yellow);
    painter.drawRect(w, 0, w, h);
    painter.setBrush(Qt::magenta);
    painter.drawRect(0, h, w, h);
    painter.setBrush(Qt::cyan);
    painter.drawRect(w, h, w, h);
}

void ZoomWidget::mousePressEvent(QMouseEvent *event)
{
    m_mousePressed = true;
    m_mousePrevPos = event->pos();
}

void ZoomWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_mousePressed = false;
}

void ZoomWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!m_mousePressed)
        return;
    QPointF dMousePos = event->pos() - m_mousePrevPos;
    m_camPos -= dMousePos / m_scale;
    m_mousePrevPos = event->pos();
    repaint();
}

void ZoomWidget::wheelEvent(QWheelEvent *event)
{
    const qreal scaleCoef = 1.1;
    qreal newScale = event->angleDelta().y() > 0 ? m_scale * scaleCoef :
        m_scale / scaleCoef;
    QPointF dCam = QPointF(event->pos()) * (1. / m_scale - 1. / newScale);
    m_camPos += dCam;
    m_scale = newScale;
    m_mousePrevPos = event->pos();
    repaint();
}

