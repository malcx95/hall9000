from datetime import datetime
from server import db
from werkzeug.security import generate_password_hash, check_password_hash
from flask_login import UserMixin
from server import login

class User(UserMixin, db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(64), index=True, unique=True)
    email = db.Column(db.String(120), index=True, unique=True)
    password_hash = db.Column(db.String(128))
    posts = db.relationship('Post', backref='author', lazy='dynamic')

    def __repr__(self):
        return '<User {}>'.format(self.username)

    def set_password(self, password):
        self.password_hash = generate_password_hash(password)

    def check_password(self, password):
        return check_password_hash(self.password_hash, password)


class Post(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    body = db.Column(db.String(140))
    timestamp = db.Column(db.DateTime, index=True, default=datetime.utcnow)
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'))

    def __repr__(self):
        return '<Post {}>'.format(self.body)

@login.user_loader
def load_user(id):
    return User.query.get(int(id))

    
class Book(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    title = db.Column(db.String(64), index=True, unique=True)
    author = db.Column(db.String(120), index=True, unique=True)
    content = db.Column(db.String(128))
    img = db.Column(db.String(128))
#    posts = db.relationship('Post', backref='author', lazy='dynamic')

    def __repr__(self):
        return '<Book {}>'.format(self.title, self.author, self.content, self.img)

    def re_wright_book(self, new_content):
        self.content = new_content

class Cform(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    firstnamn = db.Column(db.String(128))
    lastname = db.Column(db.String(128))
    email = db.Column(db.String(128))
    msg = db.Column(db.Text)

    def __repr__(self):
        return '<Cform {}>'.format(self.firstnamn, self.lastname, self.email, self.msg)

    def change_the_truth(self, new_content):
        self.content = new_content








