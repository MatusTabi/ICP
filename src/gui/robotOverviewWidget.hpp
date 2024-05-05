/**
 * @file robotOverviewWidget.hpp
 *
 * @brief The file contains the declaration of the RobotOverviewWidget class.
 *
 * The class represents a widget that displays the overview of the selected
 * robot.
 *
 * @author Matus Tabi
 */

#ifndef ROBOT_OVERVIEW_WIDGET_HPP
#define ROBOT_OVERVIEW_WIDGET_HPP

#include <QDoubleValidator>
#include <QFont>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QLabel>
#include <QLineEdit>
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "../controllers/controller.hpp"
#include "../models/robotBase.hpp"

class RobotOverviewWidget : public QWidget {
    Q_OBJECT
  public:
    /**
     * @brief Constructor of the RobotOverviewWidget class.
     */
    RobotOverviewWidget(QWidget *parent = nullptr);

    /**
     * @brief Destructor of the RobotOverviewWidget class.
     */
    ~RobotOverviewWidget();

    /**
     * @brief Sets the robot's overview.
     */
    void robot_overview();

  signals:

    /**
     * @brief Signal that is emitted when the robot's position is updated.
     */
    void redraw();

  protected:
    /**
     * @brief Paints the widget.
     *
     * @param event The paint event.
     */
    void paintEvent(QPaintEvent *event) override;

  private slots:

    /**
     * @brief Updates the robot's position.
     */
    void update_robot_position();

    /**
     * @brief Updates the robot's velocity.
     */
    void update_robot_velocity();

    /**
     * @brief Updates the robot's collision distance.
     */
    void update_collision_distance();

    /**
     * @brief Updates the robot's rotation angle.
     */
    void update_rotation_angle();

    /**
     * @brief Updates the robot's angular speed.
     */
    void update_angular_speed();

    /**
     * @brief Updates the robot's rotation direction.
     */
    void update_rotation_direction();

  private:
    /**
     * @brief Creates a text field.
     *
     * @param width The width of the text field.
     * @param style The style of the text field.
     * @param validator The validator of the text field.
     * @param slot The slot of the text field.
     *
     * @return The created text field.
     */
    QLineEdit *create_text_field(const int width, const QString &style,
                                 const QValidator *validator,
                                 void (RobotOverviewWidget::*slot)());

    /**
     * @brief Creates position text fields.
     *
     * @param layout The layout to add the text fields to.
     */
    void position_text_fields(QVBoxLayout *layout);

    /**
     * @brief Creates velocity text fields.
     *
     * @param layout The layout to add the text fields to.
     */
    void velocity_text_fields(QVBoxLayout *layout);

    /**
     * @brief Creates collision distance text field.
     *
     * @param layout The layout to add the text field to.
     */
    void collision_distance_text_field(QVBoxLayout *layout);

    /**
     * @brief Creates rotation angle text field.
     *
     * @param layout The layout to add the text field to.
     */
    void rotation_angle_text_field(QVBoxLayout *layout);

    /**
     * @brief Creates angular speed text field.
     *
     * @param layout The layout to add the text field to.
     */
    void angular_speed_text_field(QVBoxLayout *layout);

    /**
     * @brief Creates rotation direction button.
     *
     * @param layout The layout to add the button to.
     */
    void rotation_direction_button(QVBoxLayout *layout);

    /**
     * @brief Sets the fields to readonly.
     *
     * @param readonly The readonly flag.
     */
    void set_fields_readonly(const bool readonly);

    /**
     * @brief Clears the fields.
     */
    void clear_fields();

    /**
     * @brief Updates the fields.
     *
     * @param selected_robot The selected robot.
     */
    void update_fields(RobotBase *selected_robot);

    /**
     * @brief Updates the robot's property.
     *
     * @param update_function The function to update the robot's property.
     */
    void
    update_robot_property(std::function<void(RobotBase *)> update_function);

    /**
     * @brief Changes the rotation direction icon.
     */
    void change_rotation_direction_icon();

    /**
     * @brief The controller of the application.
     */
    Controller *controller_ = nullptr;

    /**
     * @brief The x position text field.
     */
    QLineEdit *x_pos_ = nullptr;

    /**
     * @brief The y position text field.
     */
    QLineEdit *y_pos_ = nullptr;

    /**
     * @brief The x velocity text field.
     */
    QLineEdit *x_vel_ = nullptr;

    /**
     * @brief The y velocity text field.
     */
    QLineEdit *y_vel_ = nullptr;

    /**
     * @brief The collision distance text field.
     */
    QLineEdit *collision_distance_ = nullptr;

    /**
     * @brief The rotation angle text field.
     */
    QLineEdit *rotation_angle_ = nullptr;

    /**
     * @brief The angular speed text field.
     */
    QLineEdit *angular_speed_ = nullptr;

    /**
     * @brief The rotation direction button.
     */
    QPushButton *rotation_direction_ = nullptr;

    /**
     * @brief The clockwise icon.
     */
    QIcon clockwise_icon_{"icons/clockwise.png"};

    /**
     * @brief The counterclockwise icon.
     */
    QIcon counterclockwise_icon_{"icons/counterclockwise.png"};
};

#endif
