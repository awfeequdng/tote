--
-- PostgreSQL database dump
--

SET statement_timeout = 0;
SET lock_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

--
-- Name: bayo; Type: SCHEMA; Schema: -; Owner: postgres
--

CREATE SCHEMA bayo;


ALTER SCHEMA bayo OWNER TO postgres;

SET search_path = bayo, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: city; Type: TABLE; Schema: bayo; Owner: postgres; Tablespace: 
--

CREATE TABLE city (
    cityid integer NOT NULL,
    departamentid integer NOT NULL,
    cityname character varying(60) NOT NULL,
    citycreated timestamp(6) without time zone NOT NULL,
    cityupdated timestamp(6) without time zone NOT NULL
);


ALTER TABLE city OWNER TO postgres;

--
-- Name: city_cityid_seq; Type: SEQUENCE; Schema: bayo; Owner: postgres
--

CREATE SEQUENCE city_cityid_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE city_cityid_seq OWNER TO postgres;

--
-- Name: city_cityid_seq; Type: SEQUENCE OWNED BY; Schema: bayo; Owner: postgres
--

ALTER SEQUENCE city_cityid_seq OWNED BY city.cityid;


--
-- Name: client; Type: TABLE; Schema: bayo; Owner: postgres; Tablespace: 
--

CREATE TABLE client (
);


ALTER TABLE client OWNER TO postgres;

--
-- Name: country; Type: TABLE; Schema: bayo; Owner: postgres; Tablespace: 
--

CREATE TABLE country (
    countryid integer NOT NULL,
    countryname character varying(60) NOT NULL,
    countryiso2 character(2) NOT NULL,
    countryiso3 character(3) NOT NULL,
    countryflag bytea,
    countrycreated timestamp(6) without time zone NOT NULL,
    countryupdated timestamp(6) without time zone NOT NULL
);


ALTER TABLE country OWNER TO postgres;

--
-- Name: COLUMN country.countryiso3; Type: COMMENT; Schema: bayo; Owner: postgres
--

COMMENT ON COLUMN country.countryiso3 IS '
';


--
-- Name: departament; Type: TABLE; Schema: bayo; Owner: postgres; Tablespace: 
--

CREATE TABLE departament (
    departamentid integer NOT NULL,
    departamentname character varying(60) NOT NULL,
    departamentcreated timestamp(6) without time zone NOT NULL,
    departamentupdated timestamp(6) without time zone NOT NULL,
    countryid integer NOT NULL
);


ALTER TABLE departament OWNER TO postgres;

--
-- Name: departament_departamentid_seq; Type: SEQUENCE; Schema: bayo; Owner: postgres
--

CREATE SEQUENCE departament_departamentid_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE departament_departamentid_seq OWNER TO postgres;

--
-- Name: departament_departamentid_seq; Type: SEQUENCE OWNED BY; Schema: bayo; Owner: postgres
--

ALTER SEQUENCE departament_departamentid_seq OWNED BY departament.departamentid;


--
-- Name: level; Type: TABLE; Schema: bayo; Owner: postgres; Tablespace: 
--

CREATE TABLE level (
);


ALTER TABLE level OWNER TO postgres;

--
-- Name: neighborhood; Type: TABLE; Schema: bayo; Owner: postgres; Tablespace: 
--

CREATE TABLE neighborhood (
    neighborhoodid integer NOT NULL,
    cityid integer NOT NULL,
    neighborhoodname character varying(60) NOT NULL,
    neighborhoodcreated timestamp(6) without time zone NOT NULL,
    neighborhoodupdated timestamp(6) without time zone NOT NULL
);


ALTER TABLE neighborhood OWNER TO postgres;

--
-- Name: neighborhood_neighborhoodid_seq; Type: SEQUENCE; Schema: bayo; Owner: postgres
--

CREATE SEQUENCE neighborhood_neighborhoodid_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE neighborhood_neighborhoodid_seq OWNER TO postgres;

--
-- Name: neighborhood_neighborhoodid_seq; Type: SEQUENCE OWNED BY; Schema: bayo; Owner: postgres
--

ALTER SEQUENCE neighborhood_neighborhoodid_seq OWNED BY neighborhood.neighborhoodid;


--
-- Name: supplier; Type: TABLE; Schema: bayo; Owner: postgres; Tablespace: 
--

CREATE TABLE supplier (
);


ALTER TABLE supplier OWNER TO postgres;

--
-- Name: users; Type: TABLE; Schema: bayo; Owner: postgres; Tablespace: 
--

CREATE TABLE users (
);


ALTER TABLE users OWNER TO postgres;

--
-- Name: cityid; Type: DEFAULT; Schema: bayo; Owner: postgres
--

ALTER TABLE ONLY city ALTER COLUMN cityid SET DEFAULT nextval('city_cityid_seq'::regclass);


--
-- Name: departamentid; Type: DEFAULT; Schema: bayo; Owner: postgres
--

ALTER TABLE ONLY departament ALTER COLUMN departamentid SET DEFAULT nextval('departament_departamentid_seq'::regclass);


--
-- Name: neighborhoodid; Type: DEFAULT; Schema: bayo; Owner: postgres
--

ALTER TABLE ONLY neighborhood ALTER COLUMN neighborhoodid SET DEFAULT nextval('neighborhood_neighborhoodid_seq'::regclass);


--
-- Data for Name: city; Type: TABLE DATA; Schema: bayo; Owner: postgres
--

COPY city (cityid, departamentid, cityname, citycreated, cityupdated) FROM stdin;
\.


--
-- Name: city_cityid_seq; Type: SEQUENCE SET; Schema: bayo; Owner: postgres
--

SELECT pg_catalog.setval('city_cityid_seq', 1, false);


--
-- Data for Name: client; Type: TABLE DATA; Schema: bayo; Owner: postgres
--

COPY client  FROM stdin;
\.


--
-- Data for Name: country; Type: TABLE DATA; Schema: bayo; Owner: postgres
--

COPY country (countryid, countryname, countryiso2, countryiso3, countryflag, countrycreated, countryupdated) FROM stdin;
\.


--
-- Data for Name: departament; Type: TABLE DATA; Schema: bayo; Owner: postgres
--

COPY departament (departamentid, departamentname, departamentcreated, departamentupdated, countryid) FROM stdin;
\.


--
-- Name: departament_departamentid_seq; Type: SEQUENCE SET; Schema: bayo; Owner: postgres
--

SELECT pg_catalog.setval('departament_departamentid_seq', 1, false);


--
-- Data for Name: level; Type: TABLE DATA; Schema: bayo; Owner: postgres
--

COPY level  FROM stdin;
\.


--
-- Data for Name: neighborhood; Type: TABLE DATA; Schema: bayo; Owner: postgres
--

COPY neighborhood (neighborhoodid, cityid, neighborhoodname, neighborhoodcreated, neighborhoodupdated) FROM stdin;
\.


--
-- Name: neighborhood_neighborhoodid_seq; Type: SEQUENCE SET; Schema: bayo; Owner: postgres
--

SELECT pg_catalog.setval('neighborhood_neighborhoodid_seq', 1, false);


--
-- Data for Name: supplier; Type: TABLE DATA; Schema: bayo; Owner: postgres
--

COPY supplier  FROM stdin;
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: bayo; Owner: postgres
--

COPY users  FROM stdin;
\.


--
-- Name: city_pkey; Type: CONSTRAINT; Schema: bayo; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY city
    ADD CONSTRAINT city_pkey PRIMARY KEY (cityid);


--
-- Name: country_pkey; Type: CONSTRAINT; Schema: bayo; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY country
    ADD CONSTRAINT country_pkey PRIMARY KEY (countryid);


--
-- Name: departament_pkey; Type: CONSTRAINT; Schema: bayo; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY departament
    ADD CONSTRAINT departament_pkey PRIMARY KEY (departamentid);


--
-- Name: neighborhood_pkey; Type: CONSTRAINT; Schema: bayo; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY neighborhood
    ADD CONSTRAINT neighborhood_pkey PRIMARY KEY (neighborhoodid);


--
-- Name: city_departamentid_fkey; Type: FK CONSTRAINT; Schema: bayo; Owner: postgres
--

ALTER TABLE ONLY city
    ADD CONSTRAINT city_departamentid_fkey FOREIGN KEY (departamentid) REFERENCES departament(departamentid) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: departament_countryid_fkey; Type: FK CONSTRAINT; Schema: bayo; Owner: postgres
--

ALTER TABLE ONLY departament
    ADD CONSTRAINT departament_countryid_fkey FOREIGN KEY (countryid) REFERENCES country(countryid) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: neighborhood_cityid_fkey; Type: FK CONSTRAINT; Schema: bayo; Owner: postgres
--

ALTER TABLE ONLY neighborhood
    ADD CONSTRAINT neighborhood_cityid_fkey FOREIGN KEY (cityid) REFERENCES city(cityid) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- PostgreSQL database dump complete
--

