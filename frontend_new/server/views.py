from server import db, app
import json
from flask import render_template, flash, redirect, flash, redirect, url_for, request, jsonify
from server.forms import LoginForm, RegistrationForm
from server.models import User, Book, Cform
from flask_login import current_user, login_user, logout_user, login_required
from werkzeug.urls import url_parse

@app.route('/login', methods=['GET', 'POST'])
def login():
    if current_user.is_authenticated:
        return redirect(url_for('index'))
    form = LoginForm()
    if form.validate_on_submit():
            user = User.query.filter_by(username=form.username.data).first()
            if user is None or not user.check_password(form.password.data):
                flash('Invalid username or password')
                return redirect(url_for('login'))
            login_user(user, remember=form.remember_me.data)

            next_page = request.args.get('next')
            if not next_page or url_parse(next_page).netloc != '':
                next_page = url_for('index')
            return redirect(next_page)
    return render_template('login.html', title='Sign In', form=form)

#   if form.validate_on_submit():
#       user = User.query.filter_by(username=form.username.data).first()
#       if user is None or not user.check_password(form.password.data):
#           flash('Invalid username or password')
#           return redirect(url_for('login'))
#       login_user(user, remember=form.remember_me.data)
#       return redirect(url_for('index'))




@app.route('/')
@app.route('/index')
@login_required
def index():
    return render_template('index.html')
@app.route('/about')
@login_required
def about():
    return render_template('page2.html')


@app.route('/logout')
def logout():
    logout_user()
    return redirect(url_for('login'))
@app.route('/register', methods=['GET', 'POST'])
def register():
    if current_user.is_authenticated:
        return redirect(url_for('index'))
    form = RegistrationForm()
    if form.validate_on_submit():
        user = User(username=form.username.data, email=form.email.data)
        user.set_password(form.password.data)
        db.session.add(user)
        db.session.commit()
        flash('Congratulations, you are now a registered user!')
        return redirect(url_for('login'))
    return render_template('register.html', title='Register', form=form)
@login_required
@app.route('/books')
def bookpage():
    books=Book.query.all()
    print("loads bookpage and" + str(books))
    return render_template('books.html',books=books)
@login_required
@app.route('/book/<int:id>')
def get_book(id):
    book=Book.query.get(id)
    book=book.__dict__
    book.pop('_sa_instance_state')
    return json.dumps(book)
@app.route('/book_template')
def render_book():
    return render_template('book.html')


@app.route('/contact')
def contact():
    messages=Cform.query.all()
    return render_template('contact.html', messages=reversed(messages))

@app.route('/contac', methods=['POST'])
def contac():
    form=Cform()
    form.firstnamn=request.form['firstname']
    form.lastname=request.form['lastname']
    form.email=request.form['email']
    form.msg=request.form['msg']
    print("hej")
    print(form.msg)
    print(form.email)
    print(form.lastname)
    print(form.firstnamn)
    db.session.add(form)
    db.session.commit()
    return ""
