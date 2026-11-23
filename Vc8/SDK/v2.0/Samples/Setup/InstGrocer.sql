
USE [master]
GO

if exists (select * from sysdatabases where name='GrocerToGo')
  DROP DATABASE GrocerToGo
GO

   CREATE DATABASE GrocerToGo
GO


USE [GrocerToGo]
GO

/****** Object:  Table [dbo].[Categories]    Script Date: 11/8/2000 4:11:57 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[Categories]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[Categories]
GO

/****** Object:  Table [dbo].[Customers]    Script Date: 11/8/2000 4:11:57 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[Customers]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[Customers]
GO

/****** Object:  Table [dbo].[ProductDetails]    Script Date: 11/8/2000 4:11:57 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[ProductDetails]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[ProductDetails]
GO

/****** Object:  Table [dbo].[Products]    Script Date: 11/8/2000 4:11:57 PM ******/
if exists (select * from sysobjects where id = object_id(N'[dbo].[Products]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[Products]
GO

/****** Object:  Table [dbo].[Categories]    Script Date: 11/8/2000 4:11:59 PM ******/
CREATE TABLE [dbo].[Categories] (
	[CategoryID] [int] NULL ,
	[CategoryName] [nvarchar] (75) NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[Customers]    Script Date: 11/8/2000 4:11:59 PM ******/
CREATE TABLE [dbo].[Customers] (
	[CustomerID] [int] NULL ,
	[FirstName] [nvarchar] (50) NULL ,
	[LastName] [nvarchar] (50) NULL ,
	[Address] [nvarchar] (50) NULL ,
	[City] [nvarchar] (50) NULL ,
	[State] [nvarchar] (50) NULL ,
	[Zip] [nvarchar] (50) NULL ,
	[HomePhone] [nvarchar] (50) NULL ,
	[WorkPhone] [nvarchar] (50) NULL ,
	[Email] [nvarchar] (50) NULL ,
	[Reference] [nvarchar] (50) NULL ,
	[FamilyCount] [nvarchar] (50) NULL ,
	[PetCount] [nvarchar] (50) NULL ,
	[CardNumber] [nvarchar] (50) NULL ,
	[CardType] [nvarchar] (50) NULL ,
	[Expiration] [nvarchar] (50) NULL ,
	[CardName] [nvarchar] (50) NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[ProductDetails]    Script Date: 11/8/2000 4:12:00 PM ******/
CREATE TABLE [dbo].[ProductDetails] (
	[ProductID] [int] NULL ,
	[Name] [nvarchar] (50) NULL ,
	[Grams] [nvarchar] (50) NULL ,
	[Percent] [int] NULL 
) ON [PRIMARY]
GO

/****** Object:  Table [dbo].[Products]    Script Date: 11/8/2000 4:12:00 PM ******/
CREATE TABLE [dbo].[Products] (
	[ProductID] [int] NOT NULL ,
	[CategoryID] [int] NULL ,
	[ProductName] [nvarchar] (75) NOT NULL ,
	[ProductDescription] [ntext] NULL ,
	[UnitPrice] [money] NOT NULL ,
	[ImagePath] [nvarchar] (255) NULL ,
	[ServingSize] [nvarchar] (50) NULL ,
	[Servings] [int] NULL ,
	[Quantity] [int] NULL ,
	[MinOnHand] [int] NULL ,
	[MaxOnHand] [int] NULL ,
	[Manufacturer] [nvarchar] (50) NULL 
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO


create procedure [GetCategories] AS
  select CategoryId, CategoryName from Categories
GO

create procedure [GetProductsForCategory] 
  (@catId int)
AS
  select ProductId, ProductName from products where categoryId = @catId
GO

/* Insert data into Categories table */
INSERT INTO Categories (CategoryID,CategoryName) VALUES (3,'Soda')
INSERT INTO Categories (CategoryID,CategoryName) VALUES (2,'Cereal')
INSERT INTO Categories (CategoryID,CategoryName) VALUES (1,'Milk')


/* Insert data into ProductDetails table */
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (1001,'Total Fat','6g',10)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (1001,'Cholesterol','1g',3)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (1001,'Sodium','90mg',0)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (1002,'Total Fat','7g',12)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (1002,'Cholesterol','5g',8)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (1002,'Sodium','85mg',10)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (1003,'Total Fat','6g',10)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (1003,'Cholesterol','5g',7)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (1003,'Sodium','80mg',9)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (1004,'Total Fat','6g',7)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (1004,'Cholesterol','6g',8)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (1004,'Sodium','85mg',10)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (2001,'Total Fat','2g',3)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (2001,'Total Carbohydrate','23g',8)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (2001,'Potassium','290mg',8)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (2002,'Total Fat','2g',3)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (2002,'Total Carbohydrate','26g',9)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (2002,'Potassium','280mg',7)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (2003,'Total Fat','1g',1)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (2003,'Total Carbohydrate','20g',7)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (2003,'Potassium','300mg',10)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (2004,'Total Fat','0g',0)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (2004,'Total Carbohydrate','19g',7)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (2004,'Potassium','250mg',6)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (3001,'Total Fat','0g',0)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (3001,'Protein','0g',0)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (3001,'Sugars','6g',15)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (3002,'Total Fat','0g',0)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (3002,'Protein','0g',0)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (3002,'Sugars','7g',17)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (3003,'Total Fat','0g',0)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (3003,'Protein','0g',0)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (3003,'Sugars','19g',50)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (3004,'Total Fat','0g',0)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (3004,'Protein','0g',0)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (3004,'Sugars','5000g',110)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (1005,'Total Fat','6g',10)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (1005,'Cholesterol','1g',3)
INSERT INTO ProductDetails (ProductID,Name,Grams,[Percent]) VALUES (1005,'Sodium','90mg',0)


/* Insert data into Products table */
INSERT INTO Products (ProductID,CategoryID,ProductName,ProductDescription,UnitPrice,ImagePath,ServingSize,Servings,Quantity,MinOnHand,MaxOnHand,Manufacturer) VALUES (1001,1,'Chocolate City Milk','Chocolate City Milk Description',2,'milk5.gif','8 fl oz (240 mL)',8,0,0,0,'Chocolate City')
INSERT INTO Products (ProductID,CategoryID,ProductName,ProductDescription,UnitPrice,ImagePath,ServingSize,Servings,Quantity,MinOnHand,MaxOnHand,Manufacturer) VALUES (1002,1,'Bessie Brand 2% Milk','Bessie Brand 2% Milk Description',1.19,'milk1.gif','8 fl oz (240 mL)',8,0,0,0,'Milk Factory')
INSERT INTO Products (ProductID,CategoryID,ProductName,ProductDescription,UnitPrice,ImagePath,ServingSize,Servings,Quantity,MinOnHand,MaxOnHand,Manufacturer) VALUES (1003,1,'Funny Farms  Milk','Funny Farms Whole Milk Description',1.29,'milk4.gif','8 fl oz (240 mL)',10,0,0,0,'Funny Farms')
INSERT INTO Products (ProductID,CategoryID,ProductName,ProductDescription,UnitPrice,ImagePath,ServingSize,Servings,Quantity,MinOnHand,MaxOnHand,Manufacturer) VALUES (2001,2,'Fruity Pops','Fruity Pops Description',4.07,'cereal7.gif','3/4 cup (30 g)',17,0,0,0,'River Mills')
INSERT INTO Products (ProductID,CategoryID,ProductName,ProductDescription,UnitPrice,ImagePath,ServingSize,Servings,Quantity,MinOnHand,MaxOnHand,Manufacturer) VALUES (2002,2,'U.F.O.s Cereal','U.F.O.s Cereal Description',3.34,'cereal3.gif','1 cup (30 g)',10,0,0,0,'Acme Harvesters')
INSERT INTO Products (ProductID,CategoryID,ProductName,ProductDescription,UnitPrice,ImagePath,ServingSize,Servings,Quantity,MinOnHand,MaxOnHand,Manufacturer) VALUES (2003,2,'Healthy Grains','Healthy Grains Cereal Description',3.78,'cereal1.gif','3/4 cup (30 g)',17,0,0,0,'All Natural Co.')
INSERT INTO Products (ProductID,CategoryID,ProductName,ProductDescription,UnitPrice,ImagePath,ServingSize,Servings,Quantity,MinOnHand,MaxOnHand,Manufacturer) VALUES (2004,2,'Super Sugar Strike','Super Sugar Strike Description',4.17,'cereal6.gif','3/4 cup (30 g)',17,0,0,0,'Capitol Cereals')
INSERT INTO Products (ProductID,CategoryID,ProductName,ProductDescription,UnitPrice,ImagePath,ServingSize,Servings,Quantity,MinOnHand,MaxOnHand,Manufacturer) VALUES (3001,3,'Purple Rain','Brown Barrel Root Beer Description',1.1,'soda5.gif','4 fl oz (120 mL)',8,0,0,0,'BrainFade, Inc.')
INSERT INTO Products (ProductID,CategoryID,ProductName,ProductDescription,UnitPrice,ImagePath,ServingSize,Servings,Quantity,MinOnHand,MaxOnHand,Manufacturer) VALUES (3002,3,'Extreme Orange','Bargain Cola Description',0.89,'soda6.gif','6 fl oz (180 mL)',6,0,0,0,'SuperX Beverages')
INSERT INTO Products (ProductID,CategoryID,ProductName,ProductDescription,UnitPrice,ImagePath,ServingSize,Servings,Quantity,MinOnHand,MaxOnHand,Manufacturer) VALUES (3003,3,'Kona Diet Cola','Super Red Pop Soda Description',1.1,'soda7.gif','4 fl oz (120 mL)',10,0,0,0,'Kona Kola Co.')
INSERT INTO Products (ProductID,CategoryID,ProductName,ProductDescription,UnitPrice,ImagePath,ServingSize,Servings,Quantity,MinOnHand,MaxOnHand,Manufacturer) VALUES (3004,3,'Fizzy Fizzing Drink','Lemon Lime Quencher Description',1.05,'soda8.gif','6 fl oz (180 mL)',5,0,0,0,'Sparkle Co.')
INSERT INTO Products (ProductID,CategoryID,ProductName,ProductDescription,UnitPrice,ImagePath,ServingSize,Servings,Quantity,MinOnHand,MaxOnHand,Manufacturer) VALUES (1005,1,'Marigold Whole Milk','Marigold Whole Milk Description',1.39,'milk6.gif','8 fl oz (240 mL)',8,0,0,0,'Marigold Meadows')
GO

GRANT EXECUTE ON [dbo].[GetCategories] TO [public]
GO

GRANT EXECUTE ON [dbo].[GetProductsForCategory] TO [public]
GO


