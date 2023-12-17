import {Controller, Get, Param, Post, Put} from '@nestjs/common';
import {AppService} from './app.service';
import {PositionUser} from "./positionUser";

@Controller('position_user')
export class AppController {
    constructor(private readonly appService: AppService) {
    }

    @Get(':user')
    getPosition(@Param('user') user: string): PositionUser {
        return this.appService.getPosition(user);
    }

    @Put(':data')
    addUserPosition(@Param('data') data: PositionUser): Boolean {
        return this.appService.setPosition(data);
    }

    @Post(':user')
    createUser(@Param('user') user: string): Boolean {
        return this.appService.createUser(user);
    }
}
