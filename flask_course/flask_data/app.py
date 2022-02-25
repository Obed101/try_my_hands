#!/usr/bin/python3
"""
This module is for my flask app
Implementing the studies from flask course
"""
from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///db.sqlite3'
app.config['SQLALCHEMY_TRACK_MODIFICAITONS']= False
db = SQLAlchemy(app)


class Customer(db.Model):
    """"Customer table"""
    id = db.Column(db.integer, primary_key=True)
    first_name = db.Column(db.String(50), nullable=False)
    last_name = db.Column(db.String(50), nullable=False)
    address = db.Column(db.String(500), nullable=False)
    city = db.Column(db.String(50), nullable=False)
    postcode = db.Column(db.String(50), nullable=False)
    email = db.Column(db.String(50), nullable=False, unique=True)

    orders = db.Relationship('Order', backref='customer')

order_product = db.Table('order_product', 
        db.Column(' order_id', db.Interger, db.ForeignKey('order.id'), primary_key=True)
        db.Column('product_id', db.Integer, db.ForeignKey('product.id'), primary_key=True)
)


class Order(db.Model):
    """Orders Table"""
    id = db.Column(db.integer, primary_key=True)
    order_date = db.Column(db.DateTime, nullable=False, default=datetime.utcnow)
    shipped_date = db.Column(db.DateTime)
    delivered_date = db.Column(db.DateTime)
    coupon_code = db.Column(db.String(50))
    customer_id = db.column(db.Integer, db.ForeignKey('customer.id'), nullable=False)

    product = db.relationship('Product', secondary='order_product')

class Product(db.Model):
    """The Product class"""
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(35), nullable=False, unique=True)
    price = db.column(db.Integer, nullable=False)
