import {Injectable} from '@nestjs/common';
import {PositionUser, PositionUserDB} from "./positionUser";
import * as mysql from 'mysql2';
import * as process from "process";
import {Connection, Query} from "mysql2";

@Injectable()
export class AppService {
    private connection: Connection;

    constructor() {
        console.log((process.env.HOST));
        this.connection = mysql.createConnection({
            host: process.env.HOST,
            user: process.env.USER,
            password: process.env.PASSWORD,
            database: process.env.DATABASE
        });
        this.connection.connect();
    }

    getPosition(user: string): PositionUser {
        try {
            const cursor: Query = this.connection.query(`SELECT POSITION_X, POSITION_Y, NAME
                                                         FROM USERS
                                                         WHERE NAME = '${user}'`);
            const result: PositionUserDB = cursor[0];
            return {x: result.POSITION_X, y: result.POSITION_Y, user: result.NAME};
        } catch (Error) {
            console.log('Error: ' + Error);
        }
    }

    setPosition(position: PositionUser): Boolean {
        try {
            this.connection.query(`UPDATE USERS
                                   SET POSITION_X = ${position.x},
                                       POSITION_Y = ${position.y}
                                   WHERE NAME = '${position.user}'`);
        } catch (Error) {
            return false;
        }
        return true;
    }

    createUser(user: string): Boolean {
        try {
            this.connection.query(`INSERT INTO USERS (NAME, POSITION_X, POSITION_Y)
                                   VALUES ('${user}', 0, 0)`);
        } catch (Error) {
            return false;
        }
        return true;
    }

}
