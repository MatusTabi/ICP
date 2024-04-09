#ifndef SELECT_WIDGET_HPP
#define SELECT_WIDGET_HPP

#include <QWidget>
#include <QPainter>

class SelectWidget : public QWidget {
    Q_OBJECT

  public:
    SelectWidget(QWidget *parent = nullptr);
    ~SelectWidget();

  protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif
