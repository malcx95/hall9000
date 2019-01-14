use sysfs_pwm::Pwm;

fn main() {
    let pwm = Pwm::new(0, 0).expect("Failed to create pwm");

    pwm.with_exported(|| {
        pwm.enable(true).expect("Failed to enable pwm");
        pwm.set_period_ns(20_000_000).expect("Failed to set period");
        pwm.set_duty_cycle_ns(1_000_000).expect("Failed to set ds");
        loop{}
    }).unwrap();
}
