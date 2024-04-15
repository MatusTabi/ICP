#ifndef SIDEBAR_HPP
#define SIDEBAR_HPP

#include <QWidget>
#include <QPainter>

class SideBar : public QWidget {
    Q_OBJECT
  public:
    explicit SideBar(QWidget *parent = nullptr);

  protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif
