USE Cities;

GO

DROP TABLE CompanyMaterials;
DROP TABLE ProjectMaterials;
DROP TABLE Materials;
DROP TABLE Projects;
DROP TABLE Companies;
DROP TABLE Cities;

GO

CREATE TABLE Cities (
	id INT PRIMARY KEY IDENTITY(1, 1),
	name VARCHAR(32) NOT NULL,
	area INT NOT NULL
);

INSERT INTO Cities(name, area)
	VALUES ('City1', 100),
		   ('City2', 200),
		   ('City3', 300);

CREATE TABLE Companies (
	id INT PRIMARY KEY IDENTITY(1, 1),
	name VARCHAR(32) NOT NULL,
	noEmployees INT NOT NULL
);

INSERT INTO Companies(name, noEmployees)
	VALUES ('Company1', 100),
		   ('Company2', 200),
		   ('Company3', 300);

CREATE TABLE Projects (
	id INT PRIMARY KEY IDENTITY(1, 1),
	name VARCHAR(32) NOT NULL,
	start_date DATE,
	end_date DATE,
	city INT NOT NULL REFERENCES Cities(id)
);

INSERT INTO Projects(name, start_date, end_date, city)
	VALUES ('Project1', '2017-01-01', '2017-01-30', 1),
		   ('Project2', '2017-01-01', '2017-01-30', 2),
		   ('Project3', '2019-01-01', '2019-01-30', 3),
		   ('Project4', '2017-01-01', '2017-01-30', 1),
		   ('Project5', '2019-01-01', '2019-01-30', 2);

CREATE TABLE Materials (
	id INT PRIMARY KEY IDENTITY(1, 1),
	name VARCHAR(32) NOT NULL,
	price INT NOT NULL,
	quantity INT NOT NULL
);

INSERT INTO Materials(name, price, quantity)
	VALUES ('Material1', 100, 10),
		   ('Material2', 200, 20),
		   ('Material3', 300, 30);

CREATE TABLE ProjectMaterials (
	project INT NOT NULL REFERENCES Projects(id),
	material INT NOT NULL REFERENCES Materials(id),
	final_price INT NOT NULL,
	PRIMARY KEY(project, material)
);

INSERT INTO ProjectMaterials(project, material, final_price)
	VALUES (1, 1, 10),
		   (1, 2, 70),
		   (1, 3, 60),
		   (2, 1, 30),
		   (3, 1, 100),
		   (3, 3, 240),
		   (4, 1, 100),
		   (4, 2, 100),
		   (5, 1, 100);

CREATE TABLE CompanyMaterials (
	company INT NOT NULL REFERENCES Companies(id),
	material INT NOT NULL REFERENCES Materials(id),
	acquisition_date DATE NOT NULL,
	PRIMARY KEY(company, material)
);

INSERT INTO CompanyMaterials(company, material, acquisition_date)
	VALUES (1, 1, '2018-01-01'),
		   (1, 2, '2019-01-01'),
		   (2, 1, '2018-01-01'),
		   (2, 2, '2018-01-01'),
		   (3, 3, '2019-01-01');

GO

CREATE OR ALTER PROCEDURE add_material_to_project
	@material_id INT,
	@project_id INT,
	@final_price INT
AS
	IF NOT EXISTS (SELECT id FROM Materials WHERE id = @material_id) BEGIN
		PRINT 'The material does not exist!';
	END ELSE IF NOT EXISTS (SELECT id FROM Projects WHERE id = @project_id) BEGIN
		PRINT 'The project does not exist!';
	END ELSE IF EXISTS (SELECT * FROM ProjectMaterials WHERE material = @material_id AND project = @project_id) BEGIN
		PRINT 'The material is already in the project!';
	END ELSE BEGIN
		INSERT INTO ProjectMaterials(project, material, final_price)
			VALUES (@project_id, @material_id, @final_price);
	END

GO

SELECT * FROM ProjectMaterials;
EXECUTE add_material_to_project 2, 2, 80;
SELECT * FROM ProjectMaterials;

GO

CREATE OR ALTER VIEW companies_that_bought_materials_this_year
AS
	SELECT * FROM Companies WHERE id IN
		(SELECT company FROM CompanyMaterials WHERE acquisition_date BETWEEN '2019-01-01' AND '2019-12-31');

GO

SELECT * FROM companies_that_bought_materials_this_year;

GO

CREATE OR ALTER FUNCTION cities_with_maximum_material_price ()
RETURNS TABLE
AS
	RETURN
		SELECT P.city, SUM(total_price) AS total 
		FROM Projects P INNER JOIN 
			(SELECT project, SUM(final_price) AS total_price 
			FROM ProjectMaterials 
			GROUP BY project) R 
			ON P.id = R.project 
			GROUP BY P.city 
			HAVING SUM(total_price) = 
				(SELECT MAX(S.total2) 
				FROM (SELECT P2.city, SUM(total_price2) AS total2 
					 FROM Projects P2 INNER JOIN (SELECT project, SUM(final_price) AS total_price2 FROM ProjectMaterials GROUP BY project) R2 ON P2.id = R2.project 
		GROUP BY P2.city) S);

GO

SELECT * FROM cities_with_maximum_material_price();