#include "robotOverviewWidget.hpp"

RobotOverviewWidget::RobotOverviewWidget(QWidget *parent)
    : QWidget(parent), controller_(Controller::get_instance()) {
    setFixedWidth(350);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *robot_position_label = new QLabel("Robot's position");
    robot_position_label->setStyleSheet(
        "color: white; font-size: 12px; background-color: #1E1E3C;");
    layout->addWidget(robot_position_label);
    layout->setContentsMargins(20, 20, 20, 20);

    position_text_fields(layout);

    QLabel *robot_velocity_label = new QLabel("Robot's velocity");
    robot_velocity_label->setStyleSheet(
        "color: white; font-size: 12px; background-color: #1E1E3C;");
    layout->addWidget(robot_velocity_label);
    velocity_text_fields(layout);

    QLabel *collision_distance_label = new QLabel("Collision distance");
    collision_distance_label->setStyleSheet(
        "color: white; font-size: 12px; background-color: #1E1E3C;");
    layout->addWidget(collision_distance_label);
    collision_distance_text_field(layout);

    QLabel *rotation_angle_label = new QLabel("Rotation angle (degrees)");
    rotation_angle_label->setStyleSheet(
        "color: white; font-size: 12px; background-color: #1E1E3C;");
    layout->addWidget(rotation_angle_label);
    rotation_angle_text_field(layout);

    QLabel *angular_speed_label = new QLabel("Angular speed (degrees)");
    angular_speed_label->setStyleSheet(
        "color: white; font-size: 12px; background-color: #1E1E3C;");
    layout->addWidget(angular_speed_label);
    angular_speed_text_field(layout);

    QLabel *rotation_direction_label =
        new QLabel("Rotation direction (clockwise by default)");
    rotation_direction_label->setStyleSheet(
        "color: white; font-size: 12px; background-color: #1E1E3C;");
    layout->addWidget(rotation_direction_label);
    rotation_direction_button(layout);

    setLayout(layout);
    robot_overview();
}

RobotOverviewWidget::~RobotOverviewWidget() {}

void RobotOverviewWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), QColor(30, 30, 60));
    QPen pen(Qt::black, 4, Qt::SolidLine);
    painter.setPen(pen);
    painter.drawRect(rect());
}

void RobotOverviewWidget::set_fields_readonly(const bool readonly) {
    x_pos_->setReadOnly(readonly);
    y_pos_->setReadOnly(readonly);
    x_vel_->setReadOnly(readonly);
    y_vel_->setReadOnly(readonly);
    collision_distance_->setReadOnly(readonly);
    rotation_angle_->setReadOnly(readonly);
    angular_speed_->setReadOnly(readonly);
    rotation_direction_->setDisabled(readonly);
}

void RobotOverviewWidget::clear_fields() {
    x_pos_->setText("");
    y_pos_->setText("");
    x_vel_->setText("");
    y_vel_->setText("");
    collision_distance_->setText("");
    rotation_angle_->setText("");
    angular_speed_->setText("");
}

void RobotOverviewWidget::update_fields(RobotBase *selected_robot) {
    x_pos_->setText(QString::number(selected_robot->get_position().x_));
    y_pos_->setText(QString::number(selected_robot->get_position().y_));
    x_vel_->setText(QString::number(selected_robot->velocity().x_));
    y_vel_->setText(QString::number(selected_robot->velocity().y_));
    collision_distance_->setText(
        QString::number(selected_robot->collision_distance()));
    rotation_angle_->setText(QString::number(selected_robot->rotation_angle()));
    angular_speed_->setText(QString::number(selected_robot->angular_speed()));
}

void RobotOverviewWidget::robot_overview() {
    RobotBase *selected_robot = controller_->selected_robot();
    const bool readonly = !selected_robot;
    set_fields_readonly(readonly);
    if (!selected_robot) {
        clear_fields();
        return;
    }
    update_fields(selected_robot);
}

void RobotOverviewWidget::position_text_fields(QVBoxLayout *layout) {
    QHBoxLayout *text_fields_layout = new QHBoxLayout;
    x_pos_ = new QLineEdit();
    x_pos_->setFixedWidth(100);
    x_pos_->setStyleSheet("color: white;");
    x_pos_->setValidator(new QDoubleValidator());
    y_pos_ = new QLineEdit();
    y_pos_->setFixedWidth(100);
    y_pos_->setStyleSheet("color: white;");
    y_pos_->setValidator(new QDoubleValidator());
    text_fields_layout->addWidget(x_pos_);
    text_fields_layout->addWidget(y_pos_);
    text_fields_layout->setAlignment(Qt::AlignLeft);

    connect(x_pos_, &QLineEdit::editingFinished, this,
            &RobotOverviewWidget::update_robot_position);
    connect(y_pos_, &QLineEdit::editingFinished, this,
            &RobotOverviewWidget::update_robot_position);
    layout->addLayout(text_fields_layout);
}

void RobotOverviewWidget::velocity_text_fields(QVBoxLayout *layout) {
    QHBoxLayout *text_fields_layout = new QHBoxLayout;
    x_vel_ = new QLineEdit();
    x_vel_->setFixedWidth(100);
    x_vel_->setStyleSheet("color: white;");
    x_vel_->setValidator(new QDoubleValidator());
    y_vel_ = new QLineEdit();
    y_vel_->setFixedWidth(100);
    y_vel_->setStyleSheet("color: white;");
    y_vel_->setValidator(new QDoubleValidator());
    text_fields_layout->addWidget(x_vel_);
    text_fields_layout->addWidget(y_vel_);
    text_fields_layout->setAlignment(Qt::AlignLeft);

    connect(x_vel_, &QLineEdit::editingFinished, this,
            &RobotOverviewWidget::update_robot_velocity);
    connect(y_vel_, &QLineEdit::editingFinished, this,
            &RobotOverviewWidget::update_robot_velocity);

    layout->addLayout(text_fields_layout);
}

QLineEdit *
RobotOverviewWidget::create_text_field(const int width, const QString &style,
                                       const QValidator *validator,
                                       void (RobotOverviewWidget::*slot)()) {
    QLineEdit *text_field = new QLineEdit();
    text_field->setFixedWidth(width);
    text_field->setStyleSheet(style);
    text_field->setValidator(validator);
    connect(text_field, &QLineEdit::editingFinished, this, slot);
    return text_field;
}

void RobotOverviewWidget::collision_distance_text_field(QVBoxLayout *layout) {
    collision_distance_ =
        create_text_field(100, "color: white;", new QIntValidator(),
                          &RobotOverviewWidget::update_collision_distance);

    layout->addWidget(collision_distance_);
}

void RobotOverviewWidget::rotation_angle_text_field(QVBoxLayout *layout) {
    rotation_angle_ =
        create_text_field(100, "color: white;", new QIntValidator(0, 360),
                          &RobotOverviewWidget::update_rotation_angle);

    layout->addWidget(rotation_angle_);
}

void RobotOverviewWidget::angular_speed_text_field(QVBoxLayout *layout) {
    angular_speed_ =
        create_text_field(100, "color: white;", new QIntValidator(0, 360),
                          &RobotOverviewWidget::update_angular_speed);

    layout->addWidget(angular_speed_);
}

void RobotOverviewWidget::rotation_direction_button(QVBoxLayout *layout) {
    rotation_direction_ = new QPushButton(this);
    rotation_direction_->setFixedSize(32, 32);
    rotation_direction_->setIcon(clockwise_icon_);
    rotation_direction_->setIconSize(QSize(32, 32));
    rotation_direction_->setStyleSheet("color: white;");

    connect(rotation_direction_, &QPushButton::clicked, this,
            &RobotOverviewWidget::update_rotation_direction);
    layout->addWidget(rotation_direction_);
}

void RobotOverviewWidget::update_robot_property(
    std::function<void(RobotBase *)> update_function) {
    if (RobotBase *robot = controller_->selected_robot()) {
        update_function(robot);
        emit redraw();
    }
}

void RobotOverviewWidget::update_robot_position() {
    update_robot_property([this](RobotBase *robot) {
        robot->set_position(
            Vector2D(x_pos_->text().toDouble(), y_pos_->text().toDouble()));
    });
}

void RobotOverviewWidget::update_robot_velocity() {
    update_robot_property([this](RobotBase *robot) {
        robot->set_velocity(
            Vector2D(x_vel_->text().toDouble(), y_vel_->text().toDouble()));
    });
}

void RobotOverviewWidget::update_collision_distance() {
    update_robot_property([this](RobotBase *robot) {
        robot->set_collision_distance(collision_distance_->text().toInt());
    });
}

void RobotOverviewWidget::update_rotation_angle() {
    update_robot_property([this](RobotBase *robot) {
        robot->set_angle(rotation_angle_->text().toInt());
    });
}

void RobotOverviewWidget::update_angular_speed() {
    update_robot_property([this](RobotBase *robot) {
        robot->set_angular_speed(angular_speed_->text().toInt());
    });
}

void RobotOverviewWidget::update_rotation_direction() {
    update_robot_property([this](RobotBase *robot) {
        robot->set_rotation_direction(
            robot->rotation_direction() == RotationDirection::CLOCKWISE
                ? RotationDirection::COUNTERCLOCKWISE
                : RotationDirection::CLOCKWISE);
    });
    change_rotation_direction_icon();
}

void RobotOverviewWidget::change_rotation_direction_icon() {
    if (RobotBase *robot = controller_->selected_robot()) {
        rotation_direction_->setIcon(
            robot->rotation_direction() == RotationDirection::COUNTERCLOCKWISE
                ? counterclockwise_icon_
                : clockwise_icon_);
    }
}
